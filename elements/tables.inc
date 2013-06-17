<?php

require_once 'elements.inc';
require_once 'dbobject.inc';
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */




/**
 * Description of tables
 *
 * @author bretzel
 */

class table_column extends element{
    public function __construct($p, $i) {
        parent::__construct($p, null, 'td',true);
    }
    
}

/**
 * Description of tables
 *
 * @author bretzel
 */


class table_row extends element{
    var $columns;
    var $header;
    public function __construct($p, $i) {
        parent::__construct($p, $i, 'tr',true);
    }
    
    public function append_column($cid,$colspan=null, $header=null){
        if($header){
            $th  = new table_column($this, $cid);
            $th->htmltag('th',true);
            $th->text($header);
        }
        $td = new table_column($this, $cid);
        if($colspan) 
            $td->attribute('colspan',$colspan);
        $this->columns[$cid] = $td;
        return $this->columns[$cid];
    }
}

class row_header extends element
{
    public function __construct($p, $i) {
        parent::__construct($p, $i, 'th', true);
    }
}

class table_header extends element
{
    var $columns;
    var $row;
    public function __construct($p, $i) {
        parent::__construct($p, $i, 'thead', true);
        $this->row = new table_row($this,$i);    
    }
    
    
    public function append_column($cid,$colspan=null){
        $th = new table_column($this->row, $cid);
        $th->htmltag('th', true);
        $th->css('text-align', 'center');
        if($colspan)
            $th->attribute('colspan','$colspan');
        
        $this->columns[$cid] = $th;
        return $this->columns[$cid];
    }
}


class table_footer extends element
{
    var $columns;
    var $row;
    public function __construct($p, $i, $h) {
        parent::__construct($p, $i, 'tfoot', true);
        $this->row = new table_header($p,$i);
        
    }
    
    public function append_column($cid,$colspan=null){
        $th = new table_column($this->row, $cid);
        $th->htmltag('th', true);
        
        if($colspan)
            $th->attribute('colspan','$colspan');
        
        $this->columns[$cid] = $th;
        return $this->columns[$cid];
    }
}
/**
 * Description of tables
 *
 * @author bretzel
 */

class table extends element{
    var $rows = null;
    var $header=null; // The header has its own row
    var $foot=null;   // The table footer has its own row
    var $body=null;   // Mandatory sub tag in every tables
    var $caption=null; // Optional caption instance
    var $vheaders = array(); // Optional vertical headers generated before every columns
    
    
    public function __construct($p, $i) {
        parent::__construct($p, $i, 'table',true);
        $this->header = NULL;
        $this->foot   = NULL;
        $this->body = new element($this,'tbdy','tbody',true);
    }
    
    public function append_row($rid)
    {
        $this->rows[$rid] = new table_row($this->body,$rid);
        return $this->rows[$rid];
    }
    
    public function init_thead()
    {
        $h = new table_header($this, $this->id().'-header');        
        return $h;
    }
        
    public function caption($capid=null)
    {
        if($capid !== null)
            $cap = new element($this,$capid,'caption',true);
            
        return $cap;
    }
    
    
    
}
    

/**
 *   entity_table build a table with the entity data
 * 
 * @param parent element
 * @param entity instance that MUST have a field 'name' used for the title and the ...name
 */

class entity_table extends table
{
    var $entity;
    public function __construct($p, $entity) {
        parent::__construct($p, get_class($entity));
        $this->entity = $entity;
    }
    
    function generate_display($wfia)
    {
        $ct = get_class($this->entity);
        $this->caption($ct.'-caption')->text($ct);
        foreach($wfia as $D)
        {
            $name = $D->name;
            $this->entity->$name = '';
        }
        foreach($this->entity as $m => $val)
        {
            $r = $this->append_row($m.'-row');
            $c = $r->append_column($m.'-th');
            $c->htmltag('th',true);
            $c->text($m);
            $c = $r->append_column($m.'-data');
            $c->text($val);
        }
        $this->css('width', '200px');
    }
    
    
}
?>

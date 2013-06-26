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
    var $icaption=null; // Optional caption instance
    var $vheaders = array(); // Optional vertical headers generated before every columns
    
    
    public function __construct($p, $i) {
        parent::__construct($p, $i, 'table',true);
        $this->header = NULL;
        $this->foot   = NULL;
        $this->body = new element($this,'tbdy','tbody',true);
    }
    
    public function append_row($rid)
    {
        $r = new table_row($this->body,$rid);
        $this->rows[$rid] = $r;
        return $r;
    }
    
    public function init_thead()
    {
        $h = new table_header($this, $this->id().'-header');        
        return $h;
    }
        
    public element function caption($capid=null)
    {
        if($capid !== null)
            $this->icaption = new element($this,$capid,'caption',true);
            
        return $this->icaption;
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
    var $data=null;
    var $title=null;
    public function __construct($p, $data, $ctitle) {
        parent::__construct($p, $ctitle.'-data-table');
        $this->data = $data;
        $this->title = $ctitle;
    }
    
    function display()
    {
        $this->caption($this->title)->text($this->title);
        $n = 0;
        foreach($this->data as $h => $v)
        {
            $ro      = $this->append_row($h.'-head');
            $hcol    = $ro->append_column($h.'-label');
            $hcol->htmltag('th',true);
            $hcol->text($h);
            $ro->append_column($h.'-col'.$n++)->text($v);
        }
        return $this;
    }
    
    
    public static function generate_display($p, $data, $ctitle)
    {
    }
    
        
}
?>

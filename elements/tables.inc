<?php

require_once 'elements.inc';
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
        parent::__construct($p, $i, 'td',true);
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



class table_header extends element
{
    var $columns;
    var $row;
    public function __construct($p, $i) {
        parent::__construct($p, $i, 'thead', true);
        $this->row = new table_row($p,$i);
        
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
    }
    
    public function append_row($rid)
    {
        $this->rows[$rid] = new table_row($this,$rid);
        return $this->rows[$rid];
    }
    
    public function init_theader()
    {
        $h = new table_header($this, $this->id().'-header');        
        return $h;
    }
    
    public function headercolumn($hrow,$i)
    {
        $hc = new table_column($hrow, $i);
        $hc->htmltag('th', true);
        return $hc;
    }
    
    public function caption($capid=null)
    {
        if($capid !== null)
            $cap = new element($this,$capid,'caption',true);
        return $cap;
    }
    
    
    
}
    


class entity_table extends table
{
    var $entity;
    
    
}
?>

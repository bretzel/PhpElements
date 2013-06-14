<?php

require_once 'elements/element.inc';
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
    var $rows;
    var $headers;
    var $tfoot;
    var $tbody;
    var $caption;
    var $vheaders;
    
    
    public function __construct($p, $i) {
        parent::__construct($p, $i, 'table',true);
        $this->theader = NULL;
        $this->tfoot   = NULL;
    }
    
    public function append_row($rid){
        $this->rows[$rid] = new table_row($this,$rid);
        return $this->rows[$rid];
    }
    
}

?>

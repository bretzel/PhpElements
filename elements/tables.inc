<?php

require_once 'element.inc';
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of tables
 *
 * @author bretzel
 */


class table_row extends element{
    var $columns;
    public function __construct($p, $i) {
        parent::__construct($p, $i, 'tr');
    }
    
    public function append_column($cid){
        $this->columns[$cid] = new table_column($this, $cid);
        return $this->columns[$cid];
    }
}


class table_column extends element{
    public function __construct($p, $i) {
        parent::__construct($p, $i, 'td');
    }
}


class tables extends element{
    var $rows;
    var $theader;
    var $tfoot;
    
    public function __construct($p, $i) {
        parent::__construct($p, $i, 'table');
        $this->theader = NULL;
        $this->tfoot   = NULL;
    }
    
    public function append_row($rid){
        $this->rows[$rid] = new table_row($this,$rid);
        return $this->rows[$rid];
    }
    
}

?>

<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
require_once 'elements/tables.inc';



class field_infos 
{
    
}
class tfields extends table
{
    var $data = null;
    private $column_infos;
    private $schema_infos;
    
    public function __construct($p, $i, $data) {
        parent::__construct($p, $i);
    }
    
    public function schema_row($obj){
        $this->schema_infos[] = $obj;
    }
    
    public function pull_schema(){
        
    }
    
    
}


?>

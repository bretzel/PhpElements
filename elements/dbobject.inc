<?php
require_once 'elements/obj.inc';
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of dbobject
 * `fetch object` mysqli wraper
 * @author bretzel
 */
class dbobject extends obj{
   
    private $password;
    private $dbname;
    private $username;
    // No host - always localhost
    private $dbhandle;
    public function __construct($p, $uname, $pass, $dbname) {
        parent::__construct($p, $uname);
        $this->password = $pass;
        $this->dbname = $dbname;
        $this->username = $uname;
        $this->dbhandle = NULL;
    }
    
    private function connect(){
        $this->dbhandle = new mysqli('localhost', $this->username, $this->password, $this->dbname);
        $e = $this->dbhandle->errno;
        if($e > 0){
            object::throw_fatal(array('mysqli connect error #'=>$e, 'error'=>$this->dbhandle->error));
        }
        return true;
    }
    function done(){
        $this->dbhandle->close();
        $this->dbhandle = NULL;
    }
    static public function etoq($entity){
        $out = "";
        $c=0;
        foreach($entity as $colname){
            if($c>0) $out .=',';
            if(!is_callable($entity->$colname)){
                $out .= $colname;
                ++$c;
            }
        }
        return $out;
    }
    /*!
        @brief search array to key=val [ AND key=val ]... construction of the WHERE Clause...
     */
    static public function stov($s){
        $c=0;
        $out = " WHERE ";
        foreach($s as $K=>$V){
            if($c>0) $out .= " AND ";
            ++$c;
            $out .= $K .'=';
            if(!is_numeric($V)) 
                $out .= "'".$V."'";
            else
                $out .= $V;
        }
        error_log("WHERE CLAUSE='$out'");
        return $out;
    }
    /*!
        @brief execute a SELECT query on a given entity object, with a search criteria 
         
        @param $entity entity object which must be an instance of a class where the class name is the table name
        @param $search an array of [key=>value] that will form the WHERE clause, optional

     */
    function pull($entity, $search=NULL){
        $tablename = get_class($entity);
        $data = $this->select($tablename, NULL, $search);
        return $data;
    }
    
    function select($entity, $fields=NULL, $search=NULL)
    {
        $c=0;
        $f='';
        $w=NULL;
        if(is_array($fields)){
            foreach($fields as $F){
                if($c>0) $f .= ",";
                $f .= $F;
            }
        }
        else
            $f = "*";
            
        if($search){
            $w = dbobject::stov($search);
            $Q = "SELECT $f FROM $entity $w";
            
        }
        else
            $Q = "SELECT $f FROM $entity";
        error_log("QUERY: '".$Q."'");
        if(!$this->dbhandle)
            $this->connect();
        
        $res = $this->dbhandle->query($Q);
        if(!$res){// Query was a write ? Then $result = NULL.
            if($this->dbhandle->errno > 0){
                object::throw_fatal(array("mysqli error#:"=>$this->dbhandle->errno, "error:"=>$this->dbhandle->error));
            }
        }
        return $res;
    }
    
    function query_fields_infos($table_name)
    {
        $q = "SELECT * from $table_name LIMIT 0";
        if(!$this->dbhandle)
            $this->connect();
        $res = $this->dbhandle->query($q);
        if(!$res) return false;
        $a = $res->fetch_fields();
        $res->close();
        return $a;
    }
    
    
    function query($Q, $obj_instance=NULL, $obj_method=NULL)
    {
        if(!$Q) return false;
        $result = $this->dbhandle->query($Q);
        if(!$result){
            // Query was a write ? Then $result = NULL.
            if($this->dbhandle->errno > 0){
                object::throw_fatal(array("mysqli error#:"=>$this->dbhandle->errno, "error:"=>$this->dbhandle->error));
            }
        }
        if($obj_instance){
            while($row = $result->fetch_assoc()){
                if($obj_instance){
                    if($obj_method){
                        if(!$obj_instance->$obj_method($row)) break;
                    }
                    // Do something else with data rows
                }
            }
            $result->free();
            return true;
        }
        return $result;
    }
    
}

?>

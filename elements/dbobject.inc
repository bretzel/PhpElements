<?php
require_once 'elements/obj.inc';
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 * 0 MYSQL_TYPE_DECIMAL, 
 * 1 MYSQL_TYPE_TINY,
 * 2 MYSQL_TYPE_SHORT,  
 * 3 MYSQL_TYPE_LONG,		
 * 4 MYSQL_TYPE_FLOAT,  
 * 5MYSQL_TYPE_DOUBLE,		
 * 6MYSQL_TYPE_NULL,   
 * 7MYSQL_TYPE_TIMESTAMP,
 * 8MYSQL_TYPE_LONGLONG,
 * 9MYSQL_TYPE_INT24,		
 * 10MYSQL_TYPE_DATE,   
 * 11MYSQL_TYPE_TIME,
 * 12MYSQL_TYPE_DATETIME, 
 * 13MYSQL_TYPE_YEAR,
 * 14MYSQL_TYPE_NEWDATE, 
 * 15MYSQL_TYPE_VARCHAR,
 * 16MYSQL_TYPE_BIT,  
 * 17MYSQL_TYPE_NEWDECIMAL=246,
 * 18MYSQL_TYPE_ENUM=247,
 * 19MYSQL_TYPE_SET=248,
 * 20MYSQL_TYPE_TINY_BLOB=249,
 * 21MYSQL_TYPE_MEDIUM_BLOB=250,
 * 22MYSQL_TYPE_LONG_BLOB=251,
 * 23MYSQL_TYPE_BLOB=252,
 * 24MYSQL_TYPE_VAR_STRING=253,
 * 25MYSQL_TYPE_STRING=254,
 * 26MYSQL_TYPE_GEOMETRY=255
 *  
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
    public function database_name()
    {
        return $this->dbname;
    }
    private function connect(){
        // Hehehe! found the way to hide credentials! 
        $this->dbhandle = new mysqli('localhost', $_SERVER['db_user'], $_SERVER['db_pass'], $_SERVER['db_name']);
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
    
    static public function types(){
        return array(
            0=>"DECIMAL",
            1=>"BYTE",
            2=>"INT",
            3=>"INT",
            4=>"FLOAT",
            5=>"FLOAT",
            6=>"VOID",
            7=>"STAMP",
            10=>"DATE",
            11=>"TIME",
            12=>"DATETIME",
            13=>"YEAR",
            15=>"VAR_CHAR_SPEC",
            247=>"ENUM",
            249=>"SMALL_BINARY",
            250=>"MEDIUM_BINARY",
            252=>"BINARY",
            253=>"TEXT",
            254=>"STRING_256"
        );
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
    
    
    function query($Q, &$obj_instance=NULL, $obj_method=NULL)
    {
        if(!$Q) return false;
        $result = $this->dbhandle->query($Q);
        if(!$result){
            // Query was a write ? Then $result = NULL.
            if($this->dbhandle->errno > 0){
                object::throw_fatal(array("mysqli error#:"=>$this->dbhandle->errno, "error:"=>$this->dbhandle->error));
            }
            $this->dbhandle->close();
            return true;
        }
        if($obj_instance){
            while($row_object = $result->fetch_object()){
                if($obj_instance){
                    if($obj_method){
                        if(!$obj_instance->$obj_method($row_object)) break;
                    }
                    // Do something else with data rows
                }
            }
            $result->free();
            $this->dbhandle->close();
            return true;
        }
        return $result;
    }
    
    public static function pull_schema($dbm, $table_name, &$obj, $fn)
    {
        $q = "USE INFORMATION_SCHEMA";
        $dbm->query($q);
        $q = "SELECT COLUMN_NAME,"
            ."COLUMN_TYPE,"
            ."CHARACTER_SET_NAME,"
            ."IS_NULLABLE,"
            ."COLUMN_KEY,"
            ."COLUMN_DEFAULT,"
            ."EXTRA,"
            ."PRIVILEGES,"
            ."COLUMN_COMMENT"
            ." from INFORMATION_SCHEMA.COLUMNS "
            ."WHERE TABLE_NAME='".$table_name."'"
            ." AND TABLE_SCHEMA='".$dbm->database_name()."'";
        $dbm->query($q, $obj,$fn);
        
    }
    
}




?>

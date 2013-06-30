<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of ophp
 *
 * @author bretzel
 */
class obj{

    private $_parent;
    var $_id;
    private $_children;
    
    function __construct($p, $i) {
        $this->_parent = $p;
        if($p) $p->addchild($this);
        $this->_id = $i;
        
    }
    function parent() {
        return $this->_parent;
    }
    
    function addchild($c){
        //if(isset($this->_children[$c->id()])) return false;
        $this->_children[] = $c;
        return true;
    }
    function haschildren(){
        return count($this->_children) > 0;
    }
    function setparent($p)
    {
        $this->_parent = $p;
        if(isset($p)) $p->addchild($this);
    }
    
    function id(){ return $this->_id; }
    function setid($i) { $this->_id = $i;}
    
    
    function iterate_children($fn)
    {
        $str = "";
        if(count($this->_children)==0) return "";
        foreach($this->_children as $c)
            $str .= $c->$fn();
        return $str;
    }
    
    
    function apply(&$obj, $a, $fnptr){
        if(!count($a)) return;
        $output="";
        foreach ($a as $A => $value){
            $output .= $obj->$fnptr($A, $value);
        }
        return $output;
    }
    
    function each_child(&$obj, $fnptr){
        if(count($this->_children)==0) return "";
        $output = "";
        //error_log("function name: '$fnptr'");
        foreach($this->_children as $oo){
            $output .= $obj->$fnptr($oo);
        }
        return $output;
    }
    
    function qchild($_id){
        foreach ($this->_children as $oo){
            if($oo->id() === $_id) return $oo;
        }
        return false;
    }
    /**
     *
     * @param string $in string input to be parsed into a integer
     * @return integer the value returned by php preg_replace
     */

    static public function number($in) {
        return preg_replace("/[^0-9]/", '', $in);
    }
        /**
     *  Translates / Converts a given geometry value to the html/css value
     *  for error (if value is not numeric value, an empty string is returned).
     *  @param integer $value the value to translate into geometry element
     *  @param boolean $z set to true ( for the width and height ) if the value is 0 (zero) to be translated to 'auto', false otherwize ( set to 0 )
     *  @param string  $suffix suffix value to be appended after the value such as px,pt,em, etc...
     */

    static public function tr_geometry($value, $z, $suffix='px') {
        $val = $value;

        if ($val === 0) {
            if (($z))
                return "auto";
            else
                return $val . $suffix;
        }else
        if (intval($val) < 0)
            return ($val * -1) . "%";
        else
        if ($val > 0) {
            return $val . $suffix;
        }
        return '';
    }

    static public function throw_error($errornum, $errortext, $additionaltext)
    {
        $e = array('error'=>$errornum, 'text'=>$errortext,'desc'=>$additionaltext);
        object::throw_fatal($e);
    }
    static public function throw_fatal($stuff){
        $err = object::encode_array($stuff); 
        error_log($err);
        die($err);
    }
    /*
     * php::json_encode even with options do not satisfy me , injecting pure json data not possible through php's json mecanism.
     * This public static method ensure that the proper syntax is sent to the client.
     * @param array Array of $KEY=>$VALUE
     * @return string
     */

    static public function encode_array(array $parray, $key_is_str=false) {
        $txt = "{";
        $c = 0;
        if(is_array($parray)){
            foreach ($parray as $parname => $val) {
            
            if ($c > 0)
                $txt .=",";
            if($key_is_str){
                //$vv = addslashes($val);
                $txt .= "\"$parname\": \"$val\"";
            }
            else{
                // $vv = addslashes($val);
                $txt .= $parname . ": \"$val\"";
            }
            ++$c;
        }
        }
        $txt .="}";
        return $txt; // doh!!!!!!!!!!!!!!!!!
    }
    static public function serialize_entity($obj){
        $out = "{id:'".get_class($obj)."', obj:{";
        $c = 0;
        foreach($obj as $K=>$V){
            if($c>0)
                $out .= ", ";
            ++$c;
            $out .= "$K:'$V'";
        }
        $out .="}";
        return $out;
    }
    
    static public $messages;
    static public function message($mid,$text=null){
        if($text !==null) object::$messages[$mid]=$text;
        return object::$messages[$mid];
    }

}

?>

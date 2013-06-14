<?php

require_once 'elements/dbobject.inc';
class  usr{

    var $id;
    var $username;
    var $passwrd;
    var $email;
    var $alias;
    var $birth;
    var $name;
    var $alive;
    
    
    public static function login($username, $password)
    {
        $cusr = new usr;
        $cusr->username = $username;
        $cusr->passwrd = $password;
        $db = new dbobject(null, 'bretzeltux', 'lus4vr47', 'bretzeltux');
        $data = $db->pull($cusr, array('username'=>$username,'passwrd'=>$password));
        error_log('query result: '.$data->num_rows.' rows');
        if(!$data  || (!$data->num_rows)){
            if($data) $data->free();
            $db->done();
            return null;
        }
        $cusr = $data->fetch_object('usr');
        return $cusr;
    }
    
}

class users{
    private $userlist;
    private $ename;
    
    function __construct($id)
    {
        $this->ename = $id;
    }
    
    function assoc_input($row)
    {
        $u = new user; 
        foreach($row as $K => $V){
            $u->$K = $V;
        }
        $this->userlist[] = $u;
        return true;
        
    }
}
?>
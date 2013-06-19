<?php
require_once 'elements/elements.inc';
require_once 'elements/user.inc';

class service  {

    //function __construct($p, $iid){
    //    parent::__construct($p,$iid);
    //    
    // }
    
    static public function startup()
    {
        echo "OKAY, service up! :-)\n";
        if(!count($_GET)){
            
        }
        else{
            var_dump ($_GET);
            ?>
                <h4>GET method used [from external query], so $_GET must be 'visited' for each items!</h4>
            <?php
            echo "\n";
        }
        
        $e = element::div(NULL);
        $e->text("hello, world! ");
        $s = element::span($e,'span-id-test', null, "[from element:div]");
        $s->css('color', '#802020');
        
        echo $e->commit();
        exit();
    }
    static public function load_page() {
        include "mastermenu/mastermenu.php";
        $pgid = $_POST['id'];
        mastermenu::load_page($pgid);
        return true;
    }

    static public function stat_filedate() {
        $pg = $_POST['id'] . ".php";
        $data = stat("mastermenu/" . $pg);
        $stream = "[$pg], " . date("l, F d Y, H:i", $data['mtime']) . " GMT: -5";
        echo $stream;
    }

    static public function login() {
        
//         $uname = $_POST['username'];
//         $pass = $_POST['password'];
//         $u = usr::login($uname, $pass);
//         if ($u)
//             service::post_login($u);   
//         else
//             object::throw_error(1, 'loginfailed', 'username or password mismatch');
//         return true;
           $response = array("error"=>"service not available");
           $response = obj::encode_array($response,true);
           echo $response;
           exit();
    }
    
    static public function post_login($u){
        $usr_stream = object::serialize_entity($u);
        
    }
    
    
    static public function create_login_form()
    {
        
    }

}


if(! isset($_POST["service"])){
    service::startup();
}
$f = $_POST["service"];
if (method_exists("service", $f)) {
    service::$f();
    exit();
}
else
    obj::throw_fatal(array('fatal error' => $f, 'unknown service command' => $f));

?>


<?php
   //require_once 'tables.php';
   require_once 'lineinput.inc';
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of sections
 *
 * the sections code generates the layouts of the master-page which are structured as 
 * 
 * General wraper 
 * left-side sidebar
 * top-heading contents ( title, menu, login infos )
 * middle / right side sections
 * 
 * 
 * The left-side sidebar is generated dynamicaly depending on the current active top-menu item.
 * 
 * @author bretzel
 */
   
class headermenuitem extends element{
    var $text;
    var $icon;
    var $tab;
    
    public function __construct($p, $data) {
        parent::__construct($p, $data[0]);        
        $this->text = $data[0];
        $this->icon = $data[1];
        $this->tab  = $data[2];
        $this->build();
        
    }
    
    function build(){
        $this->tagname('li');
        $t  = new element($this,'tab-'.$this->id());
        $t->tagname('a',true);
        $t->attr('href', "contents/".$this->tab.".php");
        $t->addinnertext($this->text);
        $t->inlinecss('outline', 'none');
        $icn = new element($this, 'icon-'.$this->id());
        $icn->css("ui-icon ".$this->icon);
        $icn->tagname('span',true);
        $icn->attr('role', 'presentation');
        $icn->addinnertext('icon');
        $icn->inlinecss('float', 'left');
        $icn->inlinecss('vertical-align', 'middle');
        $icn->inlinecss('display', 'table-cell');
    }
    
}


class mastermenu {
    //put your code here
    
    function __construct() {
        die("WRONG - sections class cannot be instanciated!");
    }
    
    static public function masterheader($items){
        $head= new element(0,"heading");
        $head->tagname("header");
        
        mastermenu::mastermenu($head,$items);
        $head->code(
                "$(function(){ \
                    function handleSelect(event, tab) {\
                        ejs.load_page(tab.text, tab.name + '-header');
                    }\
                    var tabOpts = {\
                        select:handleSelect\
                    };\
                 $('#myTabs').tabs(tabOpts);\
                });"
        );
        
//        $js=new  element($head,'');
//        $js->tagname('script',true);
//        $js->addinnertext("$('#master-menu-wrp').tabs();");
        return $head;
    }
    
    static public function mastermenu($instance, $items){
        $div = new element($instance,'master-menu-wrp');
        $title = new element($div,'div');
        $title->css('title');
        $title->inlinecss('font-size', '12pt');
        //$title->inlinecss('text-align', 'right');
        $title->inlinecss('padding-left', '5px');
        $title->addinnertext('WELCOME TO MY HUMBLE HOME');
        $title->tagname('div',true);
        $menu = new element($div,'master-menu');
        $menu->tagname('ul');
        $menu->css('finegrain style1');
        $tab = null;
        foreach($items as $item){
            $tab = new headermenuitem($menu, $item);
        }

        mastermenu::login_form($menu);
        return $menu;
    }
        
    static public function load_page($iid){
        include 'mastermenu/'.$iid.'.php';
        // ...
    }
    
    static public function login_form($pe){

         $usrdata = new element($pe,'loginform_toggle');
         $usrdata->tagname('button',true);
         $usrdata->inlinecss('float', 'right');
         $usrdata->addinnertext('|');

        $inlineFormli = new element($pe,'login_form-usr','li');
        $inlineFormli->inlinecss('float', 'right');
        $inlineFormli->inlinecss('margin-right', '5px');
        $inlineFormli->inlinecss('display', 'none');
        $inlineFormli->attr('name', 'login_form');
        
        $iform = new element($inlineFormli,'login_form','form');
        $iform->attr('onsubmit', 'return false;');
        new lineinput($iform, 'in_username', 'username');
        new lineinput($iform, 'in_password', 'password');
        $lbl = new element($iform, 'btnlogin','button');
        $lbl->tagname('button', true);
        $lbl->addinnertext('login');
        $js = new element($pe,'s');
        $js->tagname('script', true);
        $js->addinnertext("$('#btnlogin').button({text:'login', icons: {secondary: 'ui-icon-key'}});");
        $js = new element($pe,"s");
        $js->tagname('script',true);
        //$txt = "$('#".$lbl->id()."').click(function(){ $( '#login_form-usr' ).show();});";
        $txt = "$('#".$lbl->id()."').click(function(){ elementjs.userlogin();return false;});";
        $js->addinnertext($txt);
        
    }
    
}

?>

<?php
require_once 'elements/elements.inc';

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of lineinput
 *
 * @author bretzel
 */
class lineinput extends element{
    //put your code here
    var $placeholder;
    var $clr = false;
    var $lbl = false;
    var $in=null;
    public function __construct($p, $i, $placeholder=null, $typ='text', $label=null,$clr=false) 
    {
        parent::__construct($p,$i.'-w','div',true);
        if($label){
            $this->lbl = new element($this,'$id-lbl', 'label',true);
            $this->attribute('for',$i);
            $this->lbl->text($label);
        }
        
        
        $this->in = new element($this,$i, 'input',false);
        $this->in->attribute("name",$i);
        $this->in->attribute("type",$typ);
        $this->placeholder = $placeholder;
        if($placeholder)
            $this->in->attribute("placeholder",$placeholder);
        if($clr){
            $clr = new element($this, '$id-clr', 'div', true);
            $clr->css("clear-icon");
        }
        
    }
    
    function sizes($wid, $max)
    {
        $this->in->attribute('size',$wid);
        if($max)
            $this->in->attribute('max-length',$max);
    }
    
}

?>

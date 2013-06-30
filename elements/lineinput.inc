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
    var $clr = false;
    var $lbl = false;
    var $in=null;
    public function __construct($p, $i, $placeholder=null, $typ='text', $label=null,$clr=false) 
    {
        parent::__construct(null,$i.'-w','div',true);
        if($label){
            $this->lbl = new element($this,$i.'-lbl', 'label',true);
            $this->lbl->attribute('for',$i);
            $this->lbl->text($label.':');
        }
        $this->css("white-space","nowrap")->css("vertical-align:middle")->css("display","inline-table;");
        $this->in = element::lineedit($this,$i, $placeholder);
        $this->in->attribute("type",$typ);
        $this->in->css("display","inline-table");
        
        if($clr){
            $clr = new element($this, $i.'-clr', 'div', true);
            $clr->cls("clear-icon");
            $clr->css("display","inline-table")->css("margin-top","4px");
            $clr->code("jQuery('#".$clr->id()."').click(function(){ $('#".$i."').val('');});");
        }
    }
    
    function sizes($wid, $max)
    {
        $this->in->attribute('size',$wid);
        if($max)
            $this->in->attribute('maxlength',$max);
        return $this;
    }
    
    function input_element()
    {
        return $this->in;
    }
    
}

?>

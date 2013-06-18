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
    public function __construct($p, $i, $placeholder, $typ='text') {
        parent::__construct($p, $i);
        $this->tagname('input', true);
        $this->attr('type', $typ);
        $this->attr('name', $i);
        $this->attr('placeholder', $placeholder);

        //$this->css(''); 
        $this->inlinecss('display', 'inline-table');
        $this->placeholder = $placeholder;
        $this->build();
    }
}

?>

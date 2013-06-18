<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
require_once 'elements/tables.inc';
require_once 'elements/lineinput.inc';


/**
 * Field data parameters
 * 
 */
class fielddata extends element
{
    var $label;
    var $name;
    var $length; ///< max length
    var $type;
    var $data;
    var $def;
    var $size; ///< width of the field in number of characters
    
    public function __construct($p, $i) {
        parent::__construct($p, $i);
    }
    
    function setup(string $placeholder=null, string $value=null)
    {
        $this->attribute('name', $this->name);
        if($placeholder)
            $this->attribute ('placeholder', $placeholder);
        if($value)
            $this->value = $value;
        $this->attribute('value', $value);

        switch ($this->type) {
            case 'TEXT': // line editor
                $this->htmltag('input');
                $this->attribute('type', 'text');
                break;
            case 'PASSWORD':
                $this->htmltag('input');
                $this->attribute('type', 'password');
                break;
            case 'DATE':
                $this->htmltag('input');
                $this->attribute('type', 'text');
                $this->attribute('size', '10');
                $this->cls('lineedit normal');
                $this->code("jQuery('#".$this->id().").datepicker({ changeMonth:true,changeYear:true, showOn: 'button',buttonImage: 'images/icons/calendar-blue.png', buttonImageOnly: true});");
                break;
            
            default:
                break;
        }
    }
}


class tfields extends table
{
    var $fields=null;
    var $direction=0; // 0: vertical; 1: horizontal
    
    public function __construct($p, $i) {
        parent::__construct($p, $i);
    }
    
    function add_field(fielddata $field)
    {
        $this->fields[$field->name] = $field;
    }
    
    function newfield(string $fid)
    {
        $f = new fielddata();
        $f->name = $fid;
        $this->fields[$fid] = $f;
        return $this->fields[$f->name];
    }
    
    
    
    
}


?>

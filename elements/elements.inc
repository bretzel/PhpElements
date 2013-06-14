<?php
require_once 'elements/obj.inc';
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of owidget
 *
 * @author bretzel
 */
class element extends obj{
    
    private $tag;
    private $cssclassname;
    private $inlinestylearray;
    private $attributesarray;
    private $innertext;
    private $stream="";
    private $close_tag=false;
    
    private $_g=null; ///< Geometry ('left'=>'#px', 'top'=>'#px', 'width'=>'#px', 'height'=>'#px')
    
    function __construct($p, $i, $tname=null,$close_tag=false) {
        parent::__construct($p, $i);
        if(!$tname) $tname = "div";
        $this->tag = $tname;
        $this->htmltext="";
        if(!empty($i)) 
            $this->attribute("id", $i);
        if($tname) 
            $this->tag = $tname;
        $this->close_tag = $close_tag;
    }
    
    function tagname($t,$closing=false) 
    { 
        $this->tag = $t; $this->close_tag = $closing;
    }
    
    function htmltag() 
    { 
        return $this->tag; 
    }
    
    function cssclass($cname){
        $this->attr("class", $cname);
    }
    
    function inlinestyle(){
        if(!count($this->inlinestylearray)) return false;
        $inlineattr = " style=\"" . $this->apply($this, $this->inlinestylearray, 'onserialize_selector') . " \" ";
        return $inlineattr;
    }
    
    function css($sel, $values){
        $this->inlinestylearray[$sel] = $values;
    }
    
    function attribute($attr_name, $value){
        $this->attributesarray[$attr_name] = $value;
    }
    
    function text($txt=null){
        if($txt) $this->innertext .= $txt;
        return $this->innertext;
    }
    
    function onserialize_selector($sel, $line){
        return " $sel:$line;";
    }
    
    function serialize_attr($attr_name, $value){
        return " $attr_name=\"$value\"";
    }
    
    /*!
        @brief Destroys any streamed serialization .
    */
    function clear(){
        $this->stream = "";
    }
    
    
    /*!
      @brief set dimensions of this element
      
      @note Not used yet because excepted for left and top attributes, width and height can be applied to tag attributes or css styles and I am not there yet.
    */
    function geometry($x=null,$y=null,$dx=0,$dy=0)
    {
        if($x) $this->_g['left'] = obj::tr_geometry($x);
        if($y) $this->_g['top']  = obj::tr_geometry($y);
        $this->_g['width']  = obj::tr_geometry($dx,true);
        $this->_g['height'] = obj::tr_geometry($dy,true);
    }
    
    function height($h=null)
    {
        if(!$h) return $this->_g['height'];
        $this->_g['height'] = obj::tr_geometry($h,true);
        return $this->$_g['height'];
    }
    
    function width($w=null)
    {
        if(!$h) return $this->_g['height'];
        $this->_g['width'] = obj::tr_geometry($w,true);
        return $this->$_g['width'];
    }
    
    function left($l=null)
    {
        if(!$l) return $this->_g['left'];
        $this->_g['left'] = obj::tr_geometry($l,false);
        return $this->$_g['left'];
    }
    
    function top($t=null)
    {
        if(!$t) return $this->_g['top'];
        $this->_g['top'] = obj::tr_geometry($t,false);
        return $this->$_g['top'];
    }
    
    
    function commit(){
        $this->clear();
        //error_log($this->id().'::commit(); - text:'.$this->htmltext);
        $this->stream .= "<$this->tag " . $this->apply($this, $this->attributesarray, "serialize_attr");
        
        if(count($this->inlinestylearray))
            $this->stream .= " style=\"" . $this->apply($this, $this->inlinestylearray, "onserialize_selector") . '"';
        
        if($this->close_tag){
            $this->stream .= " >\n";
            if($this->innertext)
                $this->stream .= $this->innertext ."\n";
        }
        else
            $this->stream .= " />\n";
        
        if( $this->haschildren()){
            $this->stream .= $this->iterate_children('commit');
        }
        if($this->close_tag)
            $this->stream .= "</$this->tag>\n";
        return $this->stream;
    }
    
    
    function code($cod){
        $js = new element($this->parent(), '');
        $js->tagname('script', 'true');
        $js->text($cod);
    }
    
//     function on_mouse_over($js_var, $fncall, array $args){
//         $args_line ="";
//         $c=0;
//         foreach ($args as $a){
//             $args_line .= $c ? ",$a" : $a;
//         }
//         $this->attr("$(\"#".$this->id()."\").mouseover(", $js_var.".".$fncall."(".addslashes($args_line).");");
//         
//     }
    
    public static function div($p,$i=null)
    {
        $div = new element($p,$i,'div',true);
        return $div;
    }
    
    
    public static function span($p, $i, $class=null, $text="")
    {
        $sp = new element($p,$i, 'span',true);
        if($class) 
            $sp->cssclassname($class);
        $sp->text($text);
        return $sp;
    }
    
    
    public static function alink($p,$i,$href=null, $disabled=false)
    {
        $a = new element($p,$i, 'a',true);
        if($href)
            $a->attr('href', $href);
        if($disabled)
            $a->attr("onclick",'return false;');
        
        return $a;
    }
    
    public static function lineedit($p,$i, $ph=null, $t='text', $val='', $length=null, $max=null)
    {
        $le = new element($p,$i,'input',false);
        $le->attr('name',$i);
        $le->attr('type',$t);
        $le->attr('value',$val);
        
        if($ph) 
            $le->attr('placeholder',$ph);
        return $le;
    }
    
    
}



?>

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
        $this->stream="";
        if(!empty($i)) 
            $this->attribute("id", $i);
        if($tname) 
            $this->tag = $tname;
        $this->close_tag = $close_tag;
        return $this;
    }
    
    function tag(){ return $this->tag; }
    
    function htmltag($t=null,$closing=false) 
    { 
        if($t){
            $this->tag = $t; 
            return $this;
        }
        $this->close_tag = $closing;
        return $this->tag;
    }
    
    
    function cls($cname=null){
        if($cname){
            $this->attribute("class", $cname);
            return $this;
        }
        return $this->attributesarray['class'];
    }
    
    function inlinestyle(){
        if(!count($this->inlinestylearray)) return false;
        $inlineattr = " style=\"" . $this->apply($this, $this->inlinestylearray, 'onserialize_selector') . " \" ";
        return $inlineattr;
    }
    
    function css($sel, $values){
        $this->inlinestylearray[$sel] = $values;
        return $this;
    }
    
    function attribute($attr_name, $value){
        $this->attributesarray[$attr_name] = $value;
        return $this; // for chaining
    }
    
    function text($txt=null){
        if($txt){
            $this->innertext .= $txt;
            error_log($this->tag . ":innertext:'".$this->innertext);
            return $this; // for chaining
        }
        return $this->innertext; // text contents was required. - no chaining
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
        return $this;
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
        return $this;
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
            error_log($this->id() ." :: innertext:'" . $this->innertext ."'");
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
        $js = new element($this->parent(), '', 'script',true);
        $js->text($cod);
        error_log("parent[".$this->parent()->id()."]:this[".$this->id()."]->code:".$cod);
        return $this;
    }
    
    // -------------  Some common used inline javascript events, functions... --------------
    function hover($code)
    {
        return "";
    }
    
    function click($code)
    {
        return "";
    }
    // -------------------------------------------------------------------------------------
    
    public static function div($p,$i=null)
    {
        $div = new element($p,$i,'div',true);
        return $div;
    }
    
    
    public static function span($p, $i, $class=null, $text="")
    {
        $sp = new element($p,$i, 'span',true);
        if($class) 
            $sp->cls($class);
        $sp->text($text);
        return $sp;
    }
    
    
    public static function alink($p,$i,$href=null, $disabled=false)
    {
        $a = new element($p,$i, 'a',true);
        if($href)
            $a->attribute('href', $href);
        if($disabled)
            $a->attribute("onclick",'return false;');
        
        return $a;
    }
    
    public static function lineedit($p,$i, $ph=null, $val='', $length=null, $max=null)
    {
        $le = new element($p,$i,'input',false);
        $le->attribute('name',$i);
        $le->attribute('type','text');
        $le->attribute('value',$val);
        if($length)
            $le->attribute ('length', $length);
        if($max)
            $le->attribute ('maxlength', $max);
        if($ph) 
            $le->attribute('placeholder',$ph);
        $le->cls("lineedit");
        return $le;
    }
    
    
}



?>

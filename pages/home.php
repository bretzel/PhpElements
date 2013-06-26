<?php

    require_once 'elements/elements.inc';
    require_once 'elements/lineinput.inc';
    
/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2013  <copyright holder> <email>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

 
 
/**
    home class creates the root container of the home page contents, manages the sub-elements related to the home
    
    @author Serge Lussier (bretzel), lussier.serge@gmail.com; serge.lussier@arknowledgesys.com
    
    @note `home` element must be direct child of the "#main" container, replacing anything that was under "#main"
*/

class home extends element
{
    
    public function __construct($p)
    {
        if(!$p){
            error_log("home element must be created from the `#main` element");
            exit();
        }
        if($p->id() !== "main"){
            error_log("home element must be created from the `#main` element");
            exit();
        }
        parent::__construct($p, 'home', 'div', true);
    }
    
    public static function load(){
        ?>
            <div id="home" style="width:100%; height:100%">
                <h1 id="home-title" class="page-title" >Hello, Word :-)</h1>
                <p>
                    Home of Home ... some general speaks, and links...
                </p>
                <?php
                    //$i = new lineinput(null,'test','This is a lineinput test','text','type something',true);
                    //$i->sizes(20,22);
                    //echo $i->commit();
                    
                ?>
                <!--<div class="rss" id="drdobbs-rss" style="width:500px; height:200px;overflow:auto;">
                    <h1 class="page-title">drdobbs c++ RSS:</h1>
                    <script id="feed-1372179977162309" type="text/javascript" src="http://rss.bloople.net/?url=http%3A%2F%2Fwww.drdobbs.com%2Frss%2Fcpp&showtitle=false&type=js&id=1372179977162309"></script>
                </div>
                <div class="rss" id="slashdot-rss" style="width:500px; height:200px;overflow:auto;">
                    <h1 class="page-title">Slashdot RSS:</h1>
                    <script id="feed-1372181025611212" type="text/javascript" src="http://rss.bloople.net/?url=http%3A%2F%2Frss.slashdot.org%2Fslashdot%2FSlashdot&detail=40&showtitle=false&type=js&id=1372181025611212"></script>
                </div>-->
            </div>
            <script>
                ejs.elements_id();
            </script>
            <?php
            var_dump($_ENV);
            return true;
    }
    
    
    
}

?>



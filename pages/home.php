<?php

    require_once 'elements/elements.inc';
    
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
                Hello, Word :-) 
                <h4 style='display: inline-table; padding-top:5px;'>In construction...</h4>
                <p>
                    That's right - this is me :-) 
                </p>
            </div>
        
        <?php
            $i = new lineinput
    }
    
    
    
}

?>



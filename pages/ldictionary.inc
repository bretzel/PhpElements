<?php

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
 require_once 'elements/obj.inc';
 class dictionary{
    private static $dictionary=array();

    public static function en(){
        if(!isset(dictionary::$dictionary['en']))
            dictionary::$dictionary['en']= array( 
            'logo'          => '@bretzel::home', 
            'menu-home'     => 'home', 
            'menu-blog'     => 'tiny blog', 
            'menu-projects' => 'my projects', 
            'menu-about'    => 'about', 
            'menu-contact'  => 'contact', 
            'home-title'    => 'Hello, World! :-)', 
            'blog-title' => 'My blogging world! - In construction' 
            );
        return dictionary::$dictionary['en'];
    }
    
    public static function fr(){
        if(!isset($dictionary['fr']))
            dictionary::$dictionary['fr']= array(
                'logo'          => '@bretzel::maison', 
                'menu-home'     => 'acceuil', 
                'menu-blog'     => 'mini blog', 
                'menu-projects' => 'mes projets', 
                'menu-about'    => '&agrave-propos', 
                'menu-contact'  => 'contacte', 
                'home-title'    => 'Salut, Le Monde!',
                'blog-title'    => 'Mes petits Blogs... En construction');
        return dictionary::$dictionary['fr'];
    }
}



class l_locale
{
    public static function get_locale($l)
    {
        if(method_exists("dictionary",$l)){
            $response = obj::encode_array(dictionary::$l(),true);
            echo $response;
        }
        else
        echo "{'error':'locale $l : not supported'}";
        exit();
    }
}

?>

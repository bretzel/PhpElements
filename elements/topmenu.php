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
 
 require_once  'elements/elements.inc';
 

class topmenu extends element
{
    
    public function __construct($p, $i, $tname = null, $close_tag = false)
    {
        parent::__construct($p, $i, $tname, $close_tag);
    }
    
    public static function menu_list(){
        ?>
        <table cellspacing="0" cellpadding="0" style="max-height: 26px;">
            <tr style="max-height: 26px;">
                <td>

                    &nbsp;&nbsp;
                </td>
                <td style="padding-left:3px;">|</td>
                <td>
                    <ul>
                        <li class="active" id="home">home</li>
                        <li id="projects">projects</li>
                        <li id="dicussions">discussions</li>
                        <li id="about">about</li>
                        <li id="contact">contact</li>
                        <li id="user">user</li>
                    </ul>
                    <script>
                        jQuery("li").click(
                            function(){
                                // If this isn't already active
                                if (!$(this).hasClass("active")) {
                                // Remove the class from anything that is active
                                $("li.active").removeClass("active");
                                // And make this active
                                $(this).addClass("active");
                                $("#log").append($(this).attr("id") + " activated\n");
                            }
                        });
                    </script>
                </td>
                <td style="padding-left:3px;">|</td>
                <td id="userinfo">
                    <?php
                        if(!isset($_SESSION['user'])){
                    ?>
                    <table id='login-form'>
                        <tbody>
                            <tr>
                                <td><input id="in_username" type="text" class='lineedit normal' name="in_username" lenght='16' maxlength="16"  placeholder="username" value='' title='Your username'/></td>
                                <td><input id="in_password" type="password" class='lineedit normal' name="in_password" lenght='16' maxlength="16" placeholder="password" value=''  title='Your password'/></td>
                                <td>
                                    <div id="login_button" style="cursor:pointer; width:22px; height:22px;background:url('css/images/icons-22x22/system-lock-screen1.png') 22px 22px ;" title="Register/Sign in to write messages and comments"></div>
                                    <script>$("#login_button").click(function(){ejs.userlogin();})</script>
                                </td>
                            </tr>
                            </tboby>
                    </table>
                    <?php
                        }
                        else{
                            echo "user is authentified!";
                        }
                    ?>
                </td>
                <td >
                    <div id="toggle-infos" style="cursor:pointer; width:22px; height:22px;background:url('css/images/icons-22x22/stock_person.png') 22px 22px ;" title="Toggle User Informations /or Login Form"></div>
                    <script>
                        jQuery("#login-form").toggle();
                        jQuery("#toggle-infos").click(
                            function(){
//                                 var opt = {};
//                                 jQuery("#login-form").toggle("slide",opt,500);
                                   jQuery("#login-form").toggle();
                            }
                        );
                    </script>
                </td>
            </tr>
        </table>
        <?php
    }
}

?>

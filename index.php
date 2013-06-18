<?php
//$ipath = get_include_path() . PATH_SEPARATOR . "php" . PATH_SEPARATOR . "mastermenu" . PATH_SEPARATOR . "contents";
//set_include_path($ipath);
?>
<!DOCTYPE HTML>

<html>
    <head>
        <title>&& JSR-0XFFD2</title>
        <meta http-equiv="content-type" content="text/html; charset=utf-8" />
        <meta name="description" content="" />
        <meta name="keywords" content="" />
        <link href="http://fonts.googleapis.com/css?family=Source+Sans+Pro:400,400italic,700|Open+Sans+Condensed:300,700" rel="stylesheet" />
        <script type="text/javascript" src="js/jquery.js"></script>
        <script type="text/javascript" src="js/jui.js"></script>
        <script type="text/javascript" src="js/sh_main.js"></script>
        <script type="text/javascript" src="js/sh_cpp.js"></script>
        <script src="js/ejs.js"></script>
        <link href="css/doxy.css" type="text/css" rel="stylesheet" />
        <link rel="stylesheet" href="css/jui.css" />
        <link rel="stylesheet" href="css/sh_ide-kdev.css" />
        <link rel="stylesheet" href="css/style.css" />
        <link rel="stylesheet" href="css/bretzeltux.css" />
    </head>
    <body>
        <div id="fond"> 
            <div class="ruban">     
                <h2>Hello, I am bretzel, Welcome to my Home Page! :-)</h2>
                <div id="topmenu" class="topmenu">
                    <table cellspacing="0" cellpadding="0" style="max-height: 26px;">
                        <tr style="max-height: 26px;">
                            <td>
<!--                                <div id="nav-icon"><img src='css/images/computer1.png' width="18px" height="18px"/></div>-->
                                &nbsp;&nbsp;
                            </td>
                            <td style="padding-left:3px;">|</td>
                            <td>
                                <ul>
                                    <li>home</li>
                                    <li>projects</li>
                                    <li>about</li>
                                    <li>contact</li>
                                    <li>user</li>
                                </ul>
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
                                            <td><input id="in_password" type="password" class='lineedit error' name="in_password" lenght='16' maxlength="16" placeholder="password" value=''  title='Your password'/></td>
                                            <td>
                                                <div id="login_button" style="cursor:pointer; width:22px; height:22px;background:url('css/images/icons-22x22/system-lock-screen1.png') 22px 22px ;"></div>
                                                <!--                                            <button id='login' title='login'>&nbsp;</button>
                                                                                            <script>
                                                                                                jQuery("#login").button({text:'', icons:{primary:'ui-icon-key'}});
                                                                                            </script>-->
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
                        </tr>
                    </table>
                </div>
            </div>     
            <div class="ruban_gauche"></div>
            <div class="ruban_droit"></div>
        </div>
        <div id="wrapper">
            <div id="page">
                <h1>In Construction</h1>
                <hr />
                <?php
                include 'elements/forms.inc';
                $fields = new tfields(NULL, 'fields-test');
                $f = new fielddata();
                $f->name = 'username';
                $fields->add_field($f);
                echo $f->name;
                ?>
                <br /> 
                <input id="datep" size="10" class='lineedit accepted' type="text" name="bday">
                <script>
                    jQuery("#datep").datepicker({
                        changeMonth: true,
                        changeYear: true,
                        buttonImage: 'css/images/icons/calendar-blue.png',
                        showOn: 'button'
                    });
                </script>
            </div>
            <hr />
            <footer>
                <div class="copyrights">&copy;2013, Serge Lussier (bretzel, lussier.serge@gmail.com) | Design: Serge Lussier | Graphics: Creative Common and [L]GPL | jQuery, jQueryUI </div>
            </footer>
        </div>

    </body>
</html>

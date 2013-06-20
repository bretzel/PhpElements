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
        <link rel="stylesheet" href="css/bretzeltux.css" />
    </head>
    <body>
        <div id="fond"> 
            <div class="ruban">
                <span id="Arknowledge">B<u>retze</u>l alias, Digital Home</span>
                <h2 style="font-family: 'Roboto'; padding-left:155px;">(Serge Lussier) personal stuff</h2>
                <div id="topmenu" class="topmenu">
                    <?php
                        include 'elements/topmenu.php';
                        topmenu::menu_list();
                    ?>
                </div>
            </div>
        </div>
        <style>
            .enc li{
                font-size: 8pt;
                list-style-image: url("css/images/icons/comment-blue.png");
                padding:0;
                margin:0;
            }
        </style>
        
        <div id="wrapper">
            <div id="page">
                <header>
                    <table class="enc">
                        <tr>
                            <td>
                                <li>In Construction</li>
                            </td>
                            <td>
                                <li>У стадыі будаўніцтва</li>
                            </td>
                            <td>
                                <li>In Costruzione</li>
                            </td>
                            <td>
                                <li>Á Thógáil</li>
                            </td>
                            <td>
                                <li>工事中</li>
                            </td>
                            <td>
                                <li>Υπό Κατασκευή</li>
                            </td>
                             <td>
                                <li>Construcción</li>
                            </td>
                             <td>
                                <li>En Construction</li>
                            </td>
                            <td>
                                <p>...etc.</p>
                            </td>
                        </tr>
                    </table>
                </header>
                
                <hr />
                <form class="fieldrow">
                    <table  class="fieldrow" style="width:200px;">
                        <caption>user informations</caption>
                        <tbody>
                            <tr style="border-bottom: 2px solid blue;">
                                <th>id</th>
                                <td>0000000001</td>

                            </tr>
                            <tr style="border-bottom: 2px solid blue;">
                                <th>username</th>
                                <td>my-email</td>
                            </tr>
                            <tr style="border-bottom: 2px solid blue;">
                                <th>birthdate</th>
                                <td>
                                    <input id="datep" size="10" class='lineedit accepted' type="text" name="bday" placeholder="date" title="This is a date chooser test">
                                    <script>
                                        jQuery("#datep").datepicker({
                                        changeMonth: true,
                                        changeYear: true,
                                        buttonImage: 'css/images/icons/calendar-blue.png',
                                        showOn: 'both'
                                    });
                                    ejs.login_form_check();
                                    </script>
                                </td>
                            </tr>
                            <tfoot>
                            </tfoot>
                        </tbody>
                    </table>
                </form>
            </div>
            <textarea id="log" rows="4" cols="40" value="">
            </textarea>
            <hr />
            <footer>
                <div class="copyrights">&copy;2013, Serge Lussier (bretzel, lussier.serge@gmail.com) | Design: Serge Lussier | Graphics: Serge Lussier, Creative Commons, [L]GPL | jQuery, jQueryUI </div>
            </footer>
        </div>
        <script>
//             $(function() {
//                 $( ".lineedit" ).tooltip({
//                     show: {
//                         effect: "slideDown"
//                         
//                         }
//                     }
//                 );
//                 $( "#login_button" ).tooltip({
//                     show: {
//                         effect: "slideDown"
//                         
//                         }
//                     }
//                 );
//                 $( "#toggle-infos" ).tooltip({
//                     show: {
//                         effect: "slideDown"
//                         delay: 250
//                         }
//                     }
//                 );
//             });
        </script>
    </body>
</html>

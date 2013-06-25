<?php
//$ipath = get_include_path() . PATH_SEPARATOR . "php" . PATH_SEPARATOR . "mastermenu" . PATH_SEPARATOR . "contents";
//set_include_path($ipath);
?>
<!DOCTYPE HTML>

<html>
    <head>
        <title>&& JSR-0XFFD2 bretzel</title>
        <meta http-equiv="content-type" content="text/html; charset=utf-8" />
        <meta name="description" content="" />
        <meta name="keywords" content="" />
        <link href="http://fonts.googleapis.com/css?family=Source+Sans+Pro:400,400italic,700|Open+Sans+Condensed:300,700" rel="stylesheet" />
        <script type="text/javascript" src="js/jquery.js"></script>
        <script type="text/javascript" src="js/jui.js"></script>
        <script type="text/javascript" src="js/sh_main.js"></script>
        <script type="text/javascript" src="js/sh_cpp.js"></script>
        <script src="js/ejs.js"></script>

        <link rel="stylesheet" href="css/reset.css" />
        <link rel="stylesheet" href="css/jui.css" />
        <link rel="stylesheet" href="css/sh_ide-kdev.css" />
        <link rel="stylesheet" href="css/bretzeltux.css" />

    </head>
    <body>
        <div id="pg-root">
            <div id='bretzel-logo' class="fwindow">
                <span style="float:left;font-style: italic;top:3px;position:relative;">@bretzel::homepage </span>
                <header id="main-header" style="display:inline-table;">
                <ul id="main-bar" class="box1">
                    <li id="menu-home"  name="home" class="left-margin active"  >home |</li>
                    <li id="menu-blog"  name="blog"  >blog |</li>
                    <li id="menu-projects" name="projects">personal projects |</li>
                    <li id="menu-about"   name="about">about |</li>
                    <li id="menu-contact" name="contact" class="right-margin">contact</li>
                    <script>
                        jQuery("li").click(
                            function(){
                                // If this isn't already active
                                if (!$(this).hasClass("active")) {
                                    // Remove the class from anything that is active
                                    $("li.active").removeClass("active");
                                    // And make this active
                                    $(this).addClass("active");
                                    // do the activation of this menu item
                                    $("#log").append("<h4>" + $(this).attr("id") + " activated - page id:" + $(this).attr("name") + "</h4>" );
                                    ejs.master_menu($(this).attr("name"));
                                    
                                    
                                }
                            });
                    </script>
                </ul>
                <table style="display:inline-table; text-align:left" width="200">
                    <tr>
                        <td>
                            <div id="usersection">
                            </div>
                        </td>
                    </tr>
                </table>
            </header>

            </div>
            <section id='main'>
                
            </section>
            <hr style="width:80%; left:10%; position:absolute;" />
            <footer>
                <h4> &copy;2013, Serge Lussier (bretzel), serge.lussier@arknowledgesys.com | Graphics: Creative Commons | jQuery 2.x / jQueryUI. </h4>
            </footer>
        </div> <!-- ID pg-root END -->
            <script>
                ejs.master_menu("home");
            </script>
    </body>
</html>


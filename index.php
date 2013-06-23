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
                    <li id="menu-home"  class="left-margin active"  >home |</li>
                    <li id="menu-blog"    >blog |</li>
                    <li id="menu-projects">personal projects |</li>
                    <li id="menu-about"   >about |</li>
                    <li id="menu-contact" class="right-margin">contact</li>
                    <script>
                        jQuery("li").click(
                            function(){
                                // If this isn't already active
                                if (!$(this).hasClass("active")) {
                                    // Remove the class from anything that is active
                                    $("li.active").removeClass("active");
                                    // And make this active
                                    $(this).addClass("active");
                                    //$("#log").append($(this).attr("id") + " activated\n");
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
            <br />
            <hr />
            
            <section id='main'>
                main
                <h4 style='display: inline-table; padding-top:5px;'>In construction...</h4>
            </section>
            <hr />
        </div> <!-- ID pg-root END -->
    </body>
</html>


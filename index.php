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
            <div class="ruban arknowledgesys">     
                <h2 style="font-family: 'Source Code Pro';">Bretzel's home page</h2>
                <div id="topmenu" class="topmenu">
                    <?php
                        include 'elements/topmenu.php';
                        topmenu::menu_list();
                    ?>
                </div>
            </div>     
            <!--<div class="ruban_gauche"></div>
            <div class="ruban_droit"></div>-->
        </div>
        <div id="wrapper">
            <div id="page">
                <header>
                    <h1>In Construction</h1>
                </header>
                
                <hr />
                 
                <input id="datep" size="10" class='lineedit accepted' type="text" name="bday" placeholder="date" title="This is a date chooser test">
                <script>
                    jQuery("#datep").datepicker({
                        changeMonth: true,
                        changeYear: true,
                        buttonImage: 'css/images/icons/calendar-blue.png',
                        showOn: 'both'
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

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

        <style>
            table{ border: 1px solid #ccf5ff;border-collapse:collapse; background-color: white;}
            td { border: 1px solid #ccf5ff; text-align: left; padding-left:5px; padding-right:5px;}
            th { border-right: 1px solid #ccf5ff; border-bottom: 1px solid #c0f5ff; text-align: right;background-color: #fff;}
            caption{ 
                border: 1px solid #c0f5ff;
                border-bottom : none;
                background-color: white;
            }
        </style>
    </head>
    <body>
        <div id="fond"> 
            <div class="ruban">     
                <h2>Hello, I am bretzel, Welcome to my Home Page! :-)</h2>     
            </div>     
            <div class="ruban_gauche"></div>
            <div class="ruban_droit"></div>
        </div>
        <table style="width:200px;">
            <tbody>
                <tr>
                    <th>vh1</th>
                    <td> col 1</td>
                    <td> col 2</td>
                </tr>
                <tr>
                    <th>vh2</th>
                    <td> col 1</td>
                    <td> col 2</td>
                </tr>
            </tbody>
            <caption>caption</caption>
            <thead>
                <tr>
                    <th></th><th>h1</th><th>h2</th>
                </tr>
            </thead>
            <tfoot>
                <tr>
                    <th>R:</th>
                    <th>1000.0123L</td>
                    <th>1234.0123L</td>
                </tr>
            </tfoot>
        </table>

        <table style="width:200px;">
            <caption>user informations</caption>
            <tbody>
                <tr>
                    <th>id</th>
                    <td>0000000001</td>

                </tr>
                <tr>
                    <th>username</th>
                    <td>serge.lussier@arknowledgesys.com</td>
                </tr>
            <tfoot>
            </tfoot>
        </tbody>
    </table>

    <div>
        <h3>php generated table test:</h3>
        <?php
            include 'elements/tables.inc';
            $table = new table(0, "test");
            $table->css('width', '300px');
            
            $r = $table->append_row('r1');
            $h = new row_header($r, 'h1');
            $h->text('rh');
            $c = $r->append_column('c1');
            $h->attribute('width','40px');
            $c->text('col1');
            
            $r = $table->append_row('r2');
            $h = new row_header($r, 'h2');
            $h->text('name');
            $c = $r->append_column('ce2');
            $c->text('ce2');
            
            $h = $table->init_thead();
            $c = $h->append_column('e');
            $c = $h->append_column('h');
            $c->text('head');
            $cap = $table->caption('PHP');
            $cap->text('php');
            
            echo $table->commit();
            
            
            class usr
            {
                var $id         = "00000000001";
                var $username   = "serge.lussier@arknowledgesys.com";
                var $passwd     = "secret";
                var $email      = "serge.lussier@arknowledgesys.com";
                var $alias      = "bretzel";
                var $birthdate  = "1965/04/25";
                public function __construct() {
                    ;
                }
            }
            
            
            $u = new usr;
            $ut = new entity_table(null, $u);
            $ut->generate_display();
            echo $ut->commit();
        ?>
    </div>
</body>
</html>

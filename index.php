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
            </div>     
            <div class="ruban_gauche"></div>
            <div class="ruban_droit"></div>
        </div>
        <div id="wrapper">
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
            <h3>php generated table test [with entity]:</h3>
            <?php
                include 'elements/tables.inc';

                class usr
                {
                    var $id         ="0000000001";
                    var $name       ="Serge Lussier";
                    var $username   ="serge.lussier";
                    var $email      ="serge.lussier@arknowledgesys.com";
                    var $passwd     ="secret";
                    var $alias      ="bretzel";
                    var $birthdate  ="1965/04/25 08:50";
                    var $active     = true;
                    var $admlevel   = 10;
                }
                
                $u = new usr;
                $cols = array("name","length","type","decimals");
                
                $ut = new entity_table(null, $u,'user data informations');
                echo $ut->display()->commit();
                echo "<h3>table informations:</h3>";
                    
                $mdb = new dbobject(NULL, 'bretzeltux', 'lus4vr47', 'bretzeltux');
                $data = $mdb->query_fields_infos('usr');
                
                $dbt = new table(null, 'table-informations');
                $dbt->caption("caption-id")->text("table 'usr' informations");
                $th = $dbt->init_thead();
                foreach($data as $h)
                {
                    //var_dump($h);
                    foreach($cols as $colname)
                        $th->append_column($colname.'-head')->text($colname);
                    break;
                }
                
                $types = dbobject::types();
                foreach($data as $h=>$column)
                {
                    $r = $dbt->append_row('data');
                    foreach($cols as $name)
                    {
                        error_log($name.":".$column->$name);
                        if($name=="type")
                            $r->append_column('d')->text($types[$column->$name]);
                        else
                            $r->append_column('d')->text($column->$name);
                    }
                }
                echo $dbt->commit();
            ?>
            <br /> <br />
        </div>
    </div>
</body>
</html>

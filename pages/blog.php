<?php

//require_once 'elements/elements.inc';
require_once 'elements/lineinput.inc';

class blog extends element
{
    public static function load()
    {
        ?>
        <div id="blog" style="width:100%;height:100%; display:bloc;">
            <h1 id="blog-title" class="page-title"> My blogging world! - In construction </h1>
            <p>
                Here I will put everythings I have in my brain!
            </p>
            <p>
                look!! there is nothing!!! for now! :-)...
            </p>
            <br />
            
                <table class="feuillemobile">
                <caption>table de style feuillemobile:</caption>
                <thead>
                </thead>
                <tbody>
                    <tr>
                        <th>username</th>
                        <td>bretzel</td>
                    </tr>
                    <tr>
                        <th>email</th>
                        <td>serge.lussier@arknowledgesys.com</td>
                    </tr>
                    <tr>
                        <th>long text</th>
                        <td>
                            <p>I am trying to figure out how to set a table &agrave;-la feuille mobile :-)!</p>
                            <p>Indeed there is no margins right now because the contents are immediate child of td.</p>
                            <p>Sad, the coffe drop/stain is the background, and the border-bottom draws over the stain - indeed...</p>
                            <p>But anyway, I like it! :-)</p>
                            <br /><br />
                        </td>
                    </tr>
                    <tr>
                        <th>name</th>
                        <td>
                            <?php
                                $namein = new lineinput(null, 'name','required','text',null,true);
                                echo $namein->commit();
                            ?>
                        </td>
                    </tr>

                </tbody>    
                </table>
            
        </div>
        <script>
            ejs.fill_locale('fr');
        </script>
        <?php
    }
}



?>



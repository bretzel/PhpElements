/* 
 * jquery must be charged before this file!
 * 
 */



ejs = {
    username: "",
    userdata: {name:'anonymous'},
    response:{},
    load_local: function(lang) {
        $.post("inc/services.php", {message: "load_text", l: lang})
                .done(function(data) {
            dd = eval('(' + data + ')');
            console.log(dd.NAV_001);
            ejs.commit_messages(dd);
        }
        );
    },
    commit_messages: function(data) {

        $.each(data, function(k, d) {
            //document.write(k);
            o = "#" + k;
            console.log(o + ":" + d + "\n");
            jQuery(o).html(d);
        });
    },
    pull_code: function(receiver_id, file_id) {
        $.post("inc/services.php", {message: "pull_code", code_id: file_id})
                .done(function(stream) {
            $(receiver_id).html(stream);
            return true;
        }
        );
    },
    load_article: function(aid, title, subtitle, css_icn) {
        $.post("inc/services.php", {message: "pull_article", article_id: aid, t1: title, t2: subtitle, css: css_icn})
                .done(function(stream) {
            $("#main").empty();
            $("#main").append(stream);
            return true;
        });
    },
    master_menu: function(page_id) {
        $("#main").empty().append("<div id='loading' style='text-align:center;vertical-align:middle;height:100%'><img src='css/images/loading.gif'/></div>");
        $.post("services.php", {service: "load_page", id: page_id})
                .done(function(stream) {
                    //$("#loading").fade("800");
                    $("#main").empty().append(stream);
                    return true;
                });

    },
    update_path: function(str) {
        $("#path").html("/" + str);
    },
    update_stat: function(id) {
        $.post("services.php", {message: "stat_filedate", id: id}).done(
                function(stream) {
                    $("#lastmodified").empty();
                    $("#lastmodified").append("last modified: " + stream);
                    return true;
                }
        );
    },
    on_login_input_return: function(id) {
        in_user = $("#in_username");
        in_pass = $("#in_password");
        if (id === 'in_username') {
            if ($("#in_password").val() === "") {
                $("#in_password").focus();
                return true;
            }
        }
        else
        if (id === "in_password") {
            if ($("#in_username").val() === "") {
                $("#in_username").focus();
                return true;
            }
        }

        if (in_user.val() !== "" && in_pass.val() !== "") {
            this.userlogin();            
            return true;
        }
        return true;
    },
    userlogin: function(e) {
        $.post("services.php", {service: "login", username: $('#in_username').val(), password: $('#in_password').val()})
                .done(
                function(stream) {
                    
                    ejs.response = eval('(' + stream + ')');
                    if(typeof ejs.response.error != 'undefined'){
                        $('#in_username').attr('placeholder','error');
                        $('#in_username').removeClass();
                        $('#in_username').addClass('lineedit error');
                        $('#in_username').val('');
                        $('#in_password').val('');
                        //$('#in_password').removeClass().fadeOut(400);
                        $('#in_password').addClass('lineedit error').fadeOut(500).fadeIn(500);//.removeClass('error').fadeOut(500).addClass('normal').fadeIn(500);
                        $('#in_username').addClass('lineedit error').fadeOut(500).fadeIn(500);//.removeClass('error').fadeOut(500).addClass('normal').fadeIn(500);;
                        $('#in_username').attr('placeholder','username');
                        console.log("error: " + ejs.response.error);
//                         $('#in_username').removeClass('error');
//                         $('#in_username').addClass('normal').fadeIn(1000);
//                         $('#in_password').removeClass('error').delay(1100);
//                         $('#in_password').addClass('normal');
//                         $('#in_username').attr('placeholder','username');
                        return false;
                    }
                    
                    return true;
                }
                )
                .fail(
                function(stream) {
                    
                }
        );
    },
    clear: function(id) {
        e = $("#" + id);
        e.val('');
        e.focus();
        return true;
    },
    login_form_check: function() {
        lf = $('#in_username');
        if (!lf.length)
            return false;
        lf.keyup(
                function(k) {
                    if (k.keyCode === 10 || k.keyCode === 13)
                        ejs.on_login_input_return('in_username');
                }
        );
        crl = $("#in_username-clearbtn");
        crl.click(function() {
            $('#in_username').val('').focus();
        });
        lf = $('#in_password');
        lf.keyup(
                function(k) {
                    if (k.keyCode === 10 || k.keyCode === 13)
                        ejs.on_login_input_return('in_password');
                }
        );
        crlp = $("#in_password-clearbtn");
        crlp.click(function() {
            $('#in_password').val('').focus();
        });
        return true;
    },
    post: function(data_array, rec) {
        $.ajax({
            url: 'services.php',
            type: 'POST',
            dataType: 'text',
            data: data_array,
            success: function(objdata) {
                console.log("success[text]:" + objdata);
                ejs.response = eval('(' + objdata + ')');
                console.log("resonpse:" + objdata);
            },
            error: function(objdata) {
                console.log("error:" + objdata.statusText);
            }

        });
    }
};




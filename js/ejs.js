/* 
 * jquery must be charged before this file!
 * 
 */



elementjs = {
    username: "",
    userdata: {name:'anonymous'},
    response:{},
    load_local: function(lang) {
        $.post("inc/services.php", {message: "load_text", l: lang})
                .done(function(data) {
            dd = eval('(' + data + ')');
            console.log(dd.NAV_001);
            elementjs.commit_messages(dd);
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
        $.post("services.php", {message: "load_page", id: page_id})
                .done(function(stream) {
            $("#content").empty();
            $("#content").append(stream);
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
        var d= $(elementjs);
        
        $.post("services.php", {message: "login", username: $('#in_username').val(), password: $('#in_password').val()})
                .done(
                function(stream) {
                    $(d).response = eval('(' + stream + ')');
                    if($(d).error){
                        $('#in_username').attr('placeholder','username');
                        $('#in_username').val('');
                        $('#in_password').val('');
                        return false;
                    }
                    $("#loginform").html($(d).stream);
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
                        elementjs.on_login_input_return('in_username');
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
                        elementjs.on_login_input_return('in_password');
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
                elementjs.response = eval('(' + objdata + ')');
                console.log("resonpse:" + objdata);
            },
            error: function(objdata) {
                console.log("error:" + objdata.statusText);
            }

        });
    }
};




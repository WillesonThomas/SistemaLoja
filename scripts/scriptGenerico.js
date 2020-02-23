
$(document).ready(function () {
    $(".btnLimpar").click(function () {
        location.reload();
    });

    $("#ajuda").click(function () {
        informacao();
    });

    cadastrarProduto();
    cadastrarDocumentoVenda();
    paginaLogin();
});

function validarDadoNaoNumerico(idCampo, alertaCampo, mensagemCampo) {
    var verifica = false;
    var sValor = $(idCampo).val();
    for (var i = 0; i < sValor.length; i++) {
        if (!isNaN(sValor[i])) {
            verifica = true;
        }
    }
    if ($(idCampo).val() == "" || verifica == true) {
        document.getElementById(alertaCampo).src = "imagens/icones/error.png";
        $("#" + alertaCampo).fadeIn("slow");
        $(idCampo).css("borderBottom", "solid red");
        avisoErro(mensagemCampo);
    } else {
        document.getElementById(alertaCampo).src = "imagens/icones/success.png";
        $("#" + alertaCampo).fadeIn("fast");
        $(idCampo).css("borderBottom", "solid gray");
    }
}

function validarDadoNumerico(idCampo, alertaCampo, mensagemCampo) {
    if ($(idCampo).val() == "" || isNaN($(idCampo).val())) {
        document.getElementById(alertaCampo).src = "imagens/icones/error.png";
        $("#" + alertaCampo).fadeIn("slow");
        $(idCampo).css("borderBottom", "solid red");
        avisoErro(mensagemCampo);
    } else {
        document.getElementById(alertaCampo).src = "imagens/icones/success.png";
        $("#" + alertaCampo).fadeIn("fast");
        $(idCampo).css("borderBottom", "solid gray");
    }
}

function validarDadoSemTipagem(idCampo, alertaCampo, mensagemCampo) {
    if ($(idCampo).val() == "") {
        document.getElementById(alertaCampo).src = "imagens/icones/error.png";
        $("#" + alertaCampo).fadeIn("slow");
        $(idCampo).css("borderBottom", "solid red");
        avisoErro(mensagemCampo);
    } else {
        document.getElementById(alertaCampo).src = "imagens/icones/success.png";
        $("#" + alertaCampo).fadeIn("fast");
        $(idCampo).css("borderBottom", "solid gray");
    }
}

function avisoErro(mensagem) {
    $("#divAvisoErro").fadeIn("slow");
    $("#mensagemAvisoErro").text(mensagem);
    fechar("divAvisoErro");
}

function avisoAlertaLogin() {
    $("#divAvisoAlerta").fadeIn("slow");
    $("#mensagemAvisoAlerta").text("Usuario ou Senha Incorretos!");
    fechar("divAvisoAlerta");
}

function informacao() {
    $("#divInfo").fadeIn("slow");
    $("#mensagemInfo").text("Aqui sua Ajuda!");
    fechar("divInfo");
}

function fechar(idDiv) {
    $(".fechar").click(function () {
        $("#" + idDiv).fadeOut("fast");
    });
}

function cadastrarProduto() {

    $("#campoDescricao").blur(function () {
        validarDadoNaoNumerico("#campoDescricao", "alertaDescricao", "Informe somente letras no campo Descricao");
    });

    $("#campoPrecoVenda").blur(function () {
        validarDadoNumerico("#campoPrecoVenda", "alertaPrecoVenda", "Informe somente numeros no campo 'Preco Venda'");
    });

}

function cadastrarDocumentoVenda() {
    $("#buscarProduto").on('click',function () {
        var $produto     = $("#campoCodigoProdutoDocumentoVenda").val();
        var $codigoVenda = $("#campoCodigoDocumentoVenda").val();
        $.ajax({
            url: 'ajax.php',
            type: 'POST',
            dataType: "json",
            data: {codigoProdutoVenda: $produto, codigoVenda: $codigoVenda},
            success: function (data) {
                debugger;
                window.alert(data);
                if(data.length==0){
                    avisoErro("Produto Nao Cadastrado");   
                }
                createTable(data);
            }, error: function () {
                $("#campoCodigoProdutoDocumentoVenda").html("Erro ao carregar");   
            }
        });
    });

    $("#campoCodigoProdutoDocumentoVenda").blur(function () {
        validarDadoNumerico("#campoCodigoProdutoDocumentoVenda", "alertaCodigoProdutoDocumentoVenda", "Informe somente numeros no campo 'Numero'");
    });

}

function createTable(items) {
        var rows = "";
        for (var i = 0; i < items.length; i++) {
            rows += "<tr><td>" + items[i][0] + "</td><td>" + items[i][1] + "</td><td>" + items[i][2]+"</td>";
        }
        $(rows).appendTo("#itemList tbody");
    }

function paginaLogin() {
    var sCampo01 = false;
    var sCampo02 = false;
    $("#entrarPagina").click(function () {
        if (sCampo01 == false || sCampo02 == false) {
            avisoAlertaLogin();
        }
    });

    $("#campoUsuario").blur(function () {
        sCampo01 = validarDadoSemTipagem("#campoUsuario", "alertaUsuario", "Informe algo no campo 'Usuario'");
    });

    $("#campoSenha").blur(function () {
        sCampo02 = validarDadoSemTipagem("#campoSenha", "alertaSenha", "Informe algo no campo 'Senha'");
    });
}


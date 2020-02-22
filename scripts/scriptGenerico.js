
$(document).ready(function () {
    $(".btnLimpar").click(function () {
        location.reload();
    });

    $("#ajuda").click(function () {
        informacao();
    });

    cadastrarProduto();
    cadastrarDocumentoVenda();
//    cadastrarPedido();
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

    $("#campoCodigoDocumentoVenda").blur(function () {
        validarDadoNumerico("#campoCodigoDocumentoVenda", "alertaCodigoDocumentoVenda", "Informe somente numeros no campo 'Numero'");
    });

    $("#campoTotalDocumentoVenda").blur(function () {
        validarDadoNumerico("#campoTotalDocumentoVenda", "alertaTotalDocumentoVenda", "Informe somente numeros no campo 'Total'");
    });

    $("#campoSituacaoDocumentoVenda").blur(function () {
        validarDadoNaoNumerico("#campoSituacaoDocumentoVenda", "alertaSituacaoDocumentoVenda", "Informe somente letras no campo 'Situacao'");
    });

}

function validarCep(idCampo, alertaCampo, mensagemCampo) {
    if ($(idCampo).val() == "" || isNaN($(idCampo).val())) {
        document.getElementById(alertaCampo).src = "imagens/icones/error.png";
        $("#" + alertaCampo).fadeIn("slow");
        $(idCampo).css("borderBottom", "solid red");
        avisoErro(mensagemCampo);
    } 
    else {
        document.getElementById(alertaCampo).src = "imagens/icones/success.png";
        $("#" + alertaCampo).fadeIn("fast");
        $(idCampo).css("borderBottom", "solid gray");
    }
}

function cadastrarPedido() {
    
    $("#campoCodigoPessoa").blur(function () {
        var $pessoa = $("#campoCodigoPessoa").val();
        $.ajax({
            url: 'ajax.php',
            type: 'POST',
            data: {codigoPessoa:$pessoa},
            success: function (data) {
               $("#campoDesconto").val(data); 
            }, error: function() {
               $("#campoDesconto").html("Erro ao carregar");                 
            }
        });
    });

    $("#campoCodigoProduto").blur(function () {
        var $produto = $("#campoCodigoProduto").val();
        $.ajax({
            url: 'ajax.php',
            type: 'POST',
            data: {codigoProduto:$produto},
            success: function (data) {
               $("#campoPrecoUnitario").val(data); 
            }, error: function() {
               $("#campoPrecoUnitario").html("Ocorreu um Erro!");                 
            }
        });
    });

    $("#campoQuantidade").blur(function () {
        validarDadoNumerico("#campoQuantidade", "alertaQuantidade", "Informe somente numeros no campo 'Quantidade'");
    });

    $("#campoPrecoUnitario").blur(function () {
        validarDadoNumerico("#campoPrecoUnitario", "alertaPrecoUnitario", "Informe somente numeros no campo 'Preco Unitario'");
    });

    $("#campoDesconto").blur(function () {
        validarDadoNumerico("#campoDesconto", "alertaDesconto", "Informe somente numeros no campo 'Desconto'");
    });
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


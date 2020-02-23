/**
 * Script Generico
 * @package controller
 * @author Willeson Thomas da Silva <will.thomassilva@gmail.com>
 */

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

/**
 * Realiza valida��o de dados n�o num�ricos
 * @param int    idCampo
 * @param int    alertaCampo
 * @param String mensagemCampo
 */
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

/**
 * Realiza valida��o de dados num�ricos
 * @param int    idCampo
 * @param int    alertaCampo
 * @param String mensagemCampo
 */
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

/**
 * Realiza valida��o de dados que n�o tem tipo defindo
 * @param int    idCampo
 * @param int    alertaCampo
 * @param String mensagemCampo
 */
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

/**
 * Cria��o de aviso para erros
 * @param String mensagem
 */
function avisoErro(mensagem) {
    $("#divAvisoErro").fadeIn("slow");
    $("#mensagemAvisoErro").text(mensagem);
    fechar("divAvisoErro");
}

/**
 * Cria��o de aviso do tipo alerta para a pagina de login
 */
function avisoAlertaLogin() {
    $("#divAvisoAlerta").fadeIn("slow");
    $("#mensagemAvisoAlerta").text("Usuario ou Senha Incorretos!");
    fechar("divAvisoAlerta");
}

/**
 * Cria��o da caixa de informa��o para o caso de informar uma mensagem de ajuda ao usu�rio
 */
function informacao() {
    $("#divInfo").fadeIn("slow");
    $("#mensagemInfo").text("Aqui sua Ajuda!");
    fechar("divInfo");
}

/**
 * Cria��o da bloco para fechar
 * @param int idDiv
 */
function fechar(idDiv) {
    $(".fechar").click(function () {
        $("#" + idDiv).fadeOut("fast");
    });
}

/**
 * Valida os campos do formul�rio de cadastro de produto 
 */
function cadastrarProduto() {
    $("#campoPrecoVenda").blur(function () {
        validarDadoNumerico("#campoPrecoVenda", "alertaPrecoVenda", "Informe somente numeros no campo 'Preco Venda'");
    });

}

/**
 * Valida os campos do formul�rio de cadastro de Vendas e realiza Ajax para o preenchimento da tabela com os produtos 
 */
function cadastrarDocumentoVenda() {
    $("#buscarProduto").on('click', function () {
        var $produto = $("#campoCodigoProdutoDocumentoVenda").val();
        var $codigoVenda = $("#campoCodigoDocumentoVenda").val();
        $.ajax({
            url: 'ajax.php',
            type: 'POST',
            dataType: "json",
            data: {codigoProdutoVenda: $produto, codigoVenda: $codigoVenda},
            success: function (data) {
                if (data.length == 0) {
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

/**
 * Cria��o da tabela Din�mica com base dos dados retornados pelo Ajax 
 * @param Array dados
 */
function createTable(dados) {
    var rows = "";
    for (var i = 0; i < dados.length; i++) {
        rows += "<tr><td>" + dados[i][0] + "</td><td>" + dados[i][1] + "</td><td>" + dados[i][2] + "</td>";
    }
    $(rows).appendTo("#itemList tbody");
}

/**
 * Valida os campos do formul�rio da pagina de Login 
 */
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
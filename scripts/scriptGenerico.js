
$(document).ready(function () {
    $(".btnLimpar").click(function () {
        location.reload();
    });

    $("#ajuda").click(function () {
        informacao();
    });

    cadastrarProduto();
    cadastrarPessoa();
    cadastrarPedido();
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

function cadastrarPessoa() {

    $("#campoNomePessoa").blur(function () {
        validarDadoNaoNumerico("#campoNomePessoa", "alertaNomePessoa", "Informe somente letras no campo 'Nome Pessoa'");
    });

    $("#campoCPF").blur(function () {
        validarDadoNumerico("#campoCPF", "alertaCPF", "Informe somente numeros no campo 'CPF'");
    });

    $("#campoLogradouro").blur(function () {
        validarDadoNaoNumerico("#campoLogradouro", "alertaLogradouro", "Informe somente letras no campo 'Logradouro'");
    });

    $("#campoNumero").blur(function () {
        validarDadoNumerico("#campoNumero", "alertaNumero", "Informe somente numeros no campo 'Numero'");
    });

    $("#campoBairro").blur(function () {
        validarDadoNaoNumerico("#campoBairro", "alertaBairro", "Informe somente letras no campo 'Bairro'");
    });

    $("#campoCidade").blur(function () {
        validarDadoNaoNumerico("#campoCidade", "alertaCidade", "Informe somente letras no campo 'Cidade'");
    });

    $("#campoCep").blur(function () {
        //Nova variável "cep" somente com dígitos.
        var cep = $(this).val().replace(/\D/g, '');
        debugger;
        if (cep != '') {
            var validacep = /^[0-9]{8}$/;
            if(validacep.test(cep)) {
                //Preenche os campos com "..." enquanto consulta webservice.
                $("#campoLogradouro").val("...");
                $("#campoBairro").val("...");
                $("#campoCidade").val("...");
                $("#campoEstado").val("...");

                //Consulta o webservice viacep.com.br/
                $.getJSON("https://viacep.com.br/ws/"+ cep +"/json/?callback=?", function(dados) {

                    if (!("erro" in dados)) {
                        //Atualiza os campos com os valores da consulta.
                        $("#campoLogradouro").val(dados.logradouro);
                        $("#campoBairro").val(dados.bairro);
                        $("#campoCidade").val(dados.localidade);
                        $("#campoEstado").val(dados.uf);
                    } //end if.
                    else {
                        //CEP pesquisado não foi encontrado.
                        $("#campoLogradouro").val(null);
                        $("#campoBairro").val(null);
                        $("#campoCidade").val(null);
                        $("#campoEstado").val(null);
                    }
                });
            } //end if.
            else {
                //cep é inválido.
                validarCep('#campoCep', 'alertCep', 'CEP informado é inválido');
            }
        } //end if.
        else {
            validarCep('#campoCep', 'alertCep', 'CEP informado é inválido');
        }        
    });

    $("#campoEstado").blur(function () {
        validarDadoNaoNumerico("#campoEstado", "alertaEstado", "Informe somente letras no campo 'Estado'");
    });

    $("#campoDesconto").blur(function () {
        validarDadoNumerico("#campoDesconto", "alertaDesconto", "Informe somente numeros no campo 'Desconto'");
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


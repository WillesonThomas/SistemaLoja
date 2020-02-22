<?php

require_once './Persistencia/Persistencia.inc';

if (isset($_POST['codigoPessoa'])) {
    selectPessoa($_POST['codigoPessoa']);
}

if (isset($_POST['codigoProduto'])) {
    selectProduto($_POST['codigoProduto']);
}

function selectPessoa($valor) {
    $atributos = ['TBPESSOA.PESDESCONTO'];
    $tabela = 'LOJAINFORMATICA.TBPESSOA';
    $condicao = 'TBPESSOA.PESCODIGO=' . $valor;
    $select = Persistencia::selectecBD($atributos, $tabela, $condicao);
    echo $select[0][0];
}

function selectProduto($valor) {
    $atributos = ['TBPRODUTO.PROPRECOVENDA'];
    $tabela = 'LOJAINFORMATICA.TBPRODUTO';
    $condicao = 'TBPRODUTO.PROCODIGO=' . $valor;
    $select = Persistencia::selectecBD($atributos, $tabela, $condicao);
    echo $select[0][0];
}
?>


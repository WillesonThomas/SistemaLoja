<?php

require_once './persistencia/Persistencia.inc';

if (isset($_POST['codigoProdutoVenda'])) {
    selectProduto($_POST['codigoProdutoVenda']);
}

function selectProduto($valor) {
    $atributos = ['*'];
    $tabela = 'TBPRODUTO';
    $condicao = 'TBPRODUTO.PROCODIGO=' . $valor;
    $select = Persistencia::selectecBD($atributos, $tabela, $condicao);
    echo json_encode($select);
}
?>


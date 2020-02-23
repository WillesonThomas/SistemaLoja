<?php

require_once './model/Produto.inc';
require_once './model/DocumentoVenda.inc';
require_once './persistencia/Persistencia.inc';
require_once './persistencia/PersistenciaDocumentoVenda.inc';
require_once './persistencia/PersistenciaItemVenda.inc';

if (isset($_POST['codigoProdutoVenda']) and isset($_POST['codigoVenda'])) {
    selectProduto($_POST['codigoVenda'], $_POST['codigoProdutoVenda']);
}

function selectProduto($iCodigoVenda, $iCodigoProduto) {
    $atributos = ['*'];
    $tabela = 'TBPRODUTO';
    $condicao = 'TBPRODUTO.PROCODIGO=' . $iCodigoProduto;
    $select = Persistencia::selectecBD($atributos, $tabela, $condicao);

    if(count($select)!=0){
        insereDocumentoVenda($iCodigoVenda, $iCodigoProduto);
    }

    echo json_encode($select);



}

function insereDocumentoVenda($iCodigoVenda, $iCodigoProduto) {
    $oDocumentoVenda = new DocumentoVenda();
    $oDocumentoVenda->setCodigoVenda($iCodigoVenda);
    $oDocumentoVenda->setTotal(10);
    $oDocumentoVenda->setSituacao(0);
    
    $oPersistencia = new PersistenciaDocumentoVenda();
    $oPersistencia->insert($oDocumentoVenda);
    insereItemVenda($oDocumentoVenda, $iCodigoProduto);
}

function insereItemVenda($oDocumentoVenda,$iCodigoProduto) {
    $oProduto = new Produto();
    $oProduto->setCodigo($iCodigoProduto);
    
    $oPersistenciaItemVenda = new PersistenciaItemVenda();
    $oPersistenciaItemVenda->insert($oDocumentoVenda, $oProduto);
}
?>
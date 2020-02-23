<?php

require_once './model/ModelProduto.inc';
require_once './model/ModelDocumentoVenda.inc';
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

    if (count($select) != 0) {
        insereDocumentoVenda($iCodigoVenda, $select);
    }
    echo json_encode($select);
}

function insereDocumentoVenda($iCodigoVenda, $aProduto) {
    $oPersistencia = new PersistenciaDocumentoVenda();
    $oDocumentoVenda = new ModelDocumentoVenda();
    $oDocumentoVenda->setCodigoVenda($iCodigoVenda);
    $oDocumentoVenda->setSituacao(0);
    
    $oVendaAtual = $oPersistencia->getCodigoDocumentoVenda();
    if ($oVendaAtual[0][0] == $iCodigoVenda) {
        $oDocumentoVenda->setTotal($oVendaAtual[0][1] + $aProduto[0][2]);
        $oPersistencia->update($oDocumentoVenda);
    } else {
        $oDocumentoVenda->setTotal($aProduto[0][2]);
        $oPersistencia->insert($oDocumentoVenda);
    }

    insereItemVenda($oDocumentoVenda, $aProduto);
}

function insereItemVenda($oDocumentoVenda, $aProduto) {
    $oProduto = new ModelProduto();
    $oProduto->setCodigo($aProduto[0][0]);

    $oPersistenciaItemVenda = new PersistenciaItemVenda();
    $oPersistenciaItemVenda->insert($oDocumentoVenda, $oProduto);
}

?>
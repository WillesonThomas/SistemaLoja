<?php

require_once './model/DocumentoVenda.inc';
require_once './persistencia/PersistenciaDocumentoVenda.inc';
require_once './persistencia/PersistenciaProduto.inc';
require_once './view/ViewDocumentoVenda.inc';

class ControllerDocumentoVenda {

    /** @var DocumentoVenda */
    private $DocumentoVenda;

    /** @var PersistenciaDocumentoVenda */
    private $PersistenciaDocumentoVenda;

    /** @var ViewDocumentoVenda */
    private $ViewDocumentoVenda;

    public function __construct() {
        $this->processarDados();
    }

    function getDocumentoVenda() {
        return $this->DocumentoVenda;
    }

    function setDocumentoVenda(DocumentoVenda $DocumentoVenda) {
        $this->DocumentoVenda = $DocumentoVenda;
    }

    public function cadastrar() {
        if (isset($_POST['codigoDocumentoVenda'])) {
            $this->getDocumentoVenda()->setCodigoVenda($_POST['codigoDocumentoVenda']);
            $this->getDocumentoVenda()->setSituacao(1);
            $this->PersistenciaDocumentoVenda->updateSituacao($this->DocumentoVenda);
        }
    }

    public function processarDados() {
        $oDocumentoVenda = new DocumentoVenda();
        $this->setDocumentoVenda($oDocumentoVenda);
        $this->PersistenciaDocumentoVenda = new PersistenciaDocumentoVenda();
        $persistenciaDocumetoVenda = new PersistenciaDocumentoVenda();
        $this->ViewDocumentoVenda = new ViewDocumentoVenda();

        if (isset($_GET['consulta'])) {
            $select = $this->PersistenciaDocumentoVenda->selectDocumentoVendaConfirmadas();
            $totalDocumentoVenda= $this->PersistenciaDocumentoVenda->calculaTotalDocumentoVenda(1);   
            $this->ViewDocumentoVenda->criarPaginaDocumentoVendaExibir($select,$totalDocumentoVenda);
        } else {
            $iCodigoProduto = 1;
            $selectDocumentoVenda = $persistenciaDocumetoVenda->getCodigoDocumentoVenda();
            if(count($selectDocumentoVenda)!=0){
                $iCodigoProduto += $selectDocumentoVenda[0][0];
            }
            $this->ViewDocumentoVenda->criarPaginaDocumentoVendaCadastrar($iCodigoProduto);
            $this->cadastrar();
        }
    }

}
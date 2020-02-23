<?php

require_once './model/ModelDocumentoVenda.inc';
require_once './persistencia/PersistenciaDocumentoVenda.inc';
require_once './persistencia/PersistenciaProduto.inc';
require_once './view/ViewDocumentoVenda.inc';

/**
 * Controller do Documento da Venda
 * @package controller
 * @author Willeson Thomas da Silva <will.thomassilva@gmail.com>
 */
class ControllerDocumentoVenda {

    /** @var ModelDocumentoVenda */
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

    function setDocumentoVenda(ModelDocumentoVenda $DocumentoVenda) {
        $this->DocumentoVenda = $DocumentoVenda;
    }

    /**
     * Realiza atualização da situação do Documento Venda
     */
    protected function cadastrar() {
        $iCodigoProduto = 1;
        $selectDocumentoVenda = $this->PersistenciaDocumentoVenda->getCodigoDocumentoVenda();
        if (count($selectDocumentoVenda) != 0) {
            $iCodigoProduto += $selectDocumentoVenda[0][0];
        }
        $this->ViewDocumentoVenda->criarPaginaDocumentoVendaCadastrar($iCodigoProduto);
        if (isset($_POST['codigoDocumentoVenda'])) {
            $this->getDocumentoVenda()->setCodigoVenda($_POST['codigoDocumentoVenda']);
            $this->getDocumentoVenda()->setSituacao(1);
            $this->PersistenciaDocumentoVenda->updateSituacao($this->DocumentoVenda);
        }
    }

    /**
     * Realiza Consulta no Banco de dados para exibir os dados na tela
     */
    protected function consultar() {
        $select = $this->PersistenciaDocumentoVenda->selectDocumentoVendaConfirmadas();
        $totalDocumentoVenda = $this->PersistenciaDocumentoVenda->calculaTotalDocumentoVenda(1);
        $this->ViewDocumentoVenda->criarPaginaDocumentoVendaExibir($select, $totalDocumentoVenda);
    }

    /**
     * Verifica as ações com base nos parâmetros
     */
    protected function verificaAcao() {
        switch (true) {
            case isset($_GET['consulta']):
                $this->consultar();
                break;
            default:
                $this->cadastrar();
                break;
        }
    }

    /**
     * Realiza o Processamento dos dados e verifica qual ação execultar.
     */
    protected function processarDados() {
        $oDocumentoVenda = new ModelDocumentoVenda();
        $this->setDocumentoVenda($oDocumentoVenda);
        $this->PersistenciaDocumentoVenda = new PersistenciaDocumentoVenda();
        $this->ViewDocumentoVenda = new ViewDocumentoVenda();
        $this->verificaAcao();
    }

}

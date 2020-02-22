<?php

require_once 'model/DocumentoVenda.inc';
require_once './persistencia/PersistenciaDocumentoVenda.inc';
require_once './persistencia/PersistenciaPessoa.inc';
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
        echo 'oi';
        $this->processarDados();
    }

    function getDocumentoVenda() {
        return $this->DocumentoVenda;
    }

    function setDocumentoVenda(DocumentoVenda $DocumentoVenda) {
        $this->DocumentoVenda = $DocumentoVenda;
    }

    public function alterar() {
        if ($this->validarCampos()) {
            $this->getDocumentoVenda()->setCodigoVenda($_GET['alterar']);
            $this->getDocumentoVenda()->setTotal($_POST['totalDocumentoVenda']);
            $this->getDocumentoVenda()->setSituacao($_POST['situacaoDocumentoVenda']);

            $this->PersistenciaDocumentoVenda->update($this->DocumentoVenda);
        }
    }

    public function deletar() {
        $this->getDocumentoVenda()->setCodigoVenda($_GET['deletar']);
        $this->PersistenciaDocumentoVenda->delete($this->DocumentoVenda);
    }

    public function cadastrar() {
        if ($this->validarCampos()) {
            $this->getDocumentoVenda()->setCodigoVenda($_GET['alterar']);
            $this->getDocumentoVenda()->setTotal($_POST['totalDocumentoVenda']);
            $this->getDocumentoVenda()->setSituacao($_POST['situacaoDocumentoVenda']);

            $this->PersistenciaDocumentoVenda->insert($this->DocumentoVenda);
        }
    }

//    public function validarDocumentoVenda() {
//        $listaDocumentoVendas = $this->PersistenciaDocumentoVenda->selectDocumentoVenda();
//        if (sizeof($listaDocumentoVendas) != 0) {
//            foreach ($listaDocumentoVendas as $value) {
//                if (($_POST['codigoDocumentoVenda']) == $value[6]) {
//                    if(($_POST['codigoPessoa']) == $value[2]){
//                        return true;
//                    } else {
//                        return false;
//                    }
//                }
//            }
//            return true;
//        } else {           
//        return true;
//        }
//
//    }

    public function validarCampos() {
        if (isset($_POST['codigoVenda']) and isset($_POST['totalVenda']) and ! empty($_POST['situacaoVenda'])) {
            return true;
        }
        return false;
    }

    public function processarDados() {
        $oDocumentoVenda = new DocumentoVenda();
        $this->setDocumentoVenda($oDocumentoVenda);

        $this->PersistenciaDocumentoVenda = new PersistenciaDocumentoVenda();
        $persistenciaDocumetoVenda = new PersistenciaDocumentoVenda();
        $persistenciaProduto = new PersistenciaProduto();

        $this->ViewDocumentoVenda = new ViewDocumentoVenda();

        if (isset($_GET['consulta'])) {
            $select = $this->PersistenciaDocumentoVenda->selectDocumentoVenda();
            $selectDocumentoVendas = $this->PersistenciaDocumentoVenda->selectDocumentoVendaTabela();
            foreach ($selectDocumentoVendas as $value) {
             $select = $this->PersistenciaDocumentoVenda->selectDocumentoVenda($value[0]);   
             $totalDocumentoVenda= $this->PersistenciaDocumentoVenda->calculaTotalDocumentoVenda($value[0]);   
             $this->ViewDocumentoVenda->criarPaginaDocumentoVendaExibir($select,$totalDocumentoVenda);
            }
        } else if (isset($_GET['deletar'])) {
            $selectProduto = $persistenciaProduto->select();
            $selectPessoa = $persistenciaDocumetoVenda->select();
            $this->ViewDocumentoVenda->criarPaginaDocumentoVendaCadastrar($selectPessoa, $selectProduto);
            $this->deletar();
        } else if (isset($_GET['alterar'])) {
            $this->PersistenciaDocumentoVenda->setCondicao($_GET['alterar']);
            $select = $this->PersistenciaDocumentoVenda->selectDocumentoVenda();
            $selectProduto = $persistenciaProduto->select();
            $selectPessoa = $persistenciaDocumetoVenda->select();

            $this->ViewDocumentoVenda->criarPaginaDocumentoVendaAlterar($select, $selectPessoa, $selectProduto);
            $this->alterar();
        } else if (isset($_GET['vizualizar'])) {
            $this->PersistenciaDocumentoVenda->setCondicao($_GET['vizualizar']);
            $select = $this->PersistenciaDocumentoVenda->selectDocumentoVenda();
            $selectProduto = $persistenciaProduto->select();
            $selectPessoa = $persistenciaDocumetoVenda->select();

            $this->ViewDocumentoVenda->criarPaginaDocumentoVendaVizualizar($select, $this->verificaPessoa($selectPessoa, $select[0][2]), $this->verificaProduto($selectProduto, $select[0][1]));
        } else {
            $selectProduto = $persistenciaProduto->select();
            $selectPessoa = $persistenciaDocumetoVenda->select();

            $this->ViewDocumentoVenda->criarPaginaDocumentoVendaCadastrar($selectPessoa, $selectProduto);
            $this->cadastrar();
        }
    }

    function verificaProduto($selectProduto, $select) {
        foreach ($selectProduto as $value) {
            if ($value[0] == $select) {
                return $value[1];
            }
        }
    }

    function verificaPessoa($selectPessoa, $select) {
        foreach ($selectPessoa as $value) {
            if ($value[0] == $select) {
                return $value[1];
            }
        }
    }

}

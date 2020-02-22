<?php

require_once 'model/ItemVenda.inc';
require_once './persistencia/PersistenciaItemVenda.inc';
require_once './persistencia/PersistenciaPessoa.inc';
require_once './persistencia/PersistenciaProduto.inc';
require_once './view/ViewItemVenda.inc';

class ControllerItemVenda {

    /** @var ItemVenda */
    private $ItemVenda;

    /** @var PersistenciaItemVenda */
    private $PersistenciaItemVenda;

    /** @var ViewItemVenda */
    private $ViewItemVenda;

    public function __construct() {
        $this->processarDados();
    }

    function getItemVenda() {
        return $this->ItemVenda;
    }

    function setItemVenda(ItemVenda $ItemVenda) {
        $this->ItemVenda = $ItemVenda;
    }

    public function alterar() {
        if ($this->validarCampos()) {
            $this->getItemVenda()->setCodigoOperacao($_GET['alterar']);
            $this->getItemVenda()->setCodigoPessoa($_POST['codigoPessoa']);
            $this->getItemVenda()->setCodigoProduto($_POST['codigoProduto']);
            $this->getItemVenda()->setQuantidade($_POST['quantidade']);
            $this->getItemVenda()->setPrecoUnitario($_POST['precoUnitario']);
            $this->getItemVenda()->setDesconto($_POST['desconto']);

            $this->PersistenciaItemVenda->update($this->ItemVenda);
        }
    }

    public function deletar() {
        $this->getItemVenda()->setCodigoOperacao($_GET['deletar']);
        $this->PersistenciaItemVenda->delete($this->ItemVenda);
    }

    public function cadastrar() {
        if ($this->validarCampos()) {
            echo ($_POST['codigoPessoa']);
            $this->getItemVenda()->setCodigo($_POST['codigoItemVenda']);
            $this->getItemVenda()->setCodigoPessoa($_POST['codigoPessoa']);
            $this->getItemVenda()->setCodigoProduto($_POST['codigoProduto']);
            $this->getItemVenda()->setQuantidade($_POST['quantidade']);
            $this->getItemVenda()->setPrecoUnitario($_POST['precoUnitario']);
            $this->getItemVenda()->setDesconto($_POST['desconto']);

            $this->PersistenciaItemVenda->insert($this->ItemVenda);
        }
    }

    public function validarItemVenda() {
        $listaItemVendas = $this->PersistenciaItemVenda->selectItemVenda();
        if (sizeof($listaItemVendas) != 0) {
            foreach ($listaItemVendas as $value) {
                if (($_POST['codigoItemVenda']) == $value[6]) {
                    if(($_POST['codigoPessoa']) == $value[2]){
                        return true;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        } else {           
        return true;
        }

    }

    public function validarCampos() {
        if (isset($_POST['codigoPessoa']) and isset($_POST['codigoProduto']) and ! empty($_POST['codigoPessoa']) and ! empty($_POST['codigoProduto']) and $this->validarItemVenda()) {
            return true;
        }
        return false;
    }

    public function processarDados() {
        $oItemVenda = new ItemVenda();
        $this->setItemVenda($oItemVenda);

        $this->PersistenciaItemVenda = new PersistenciaItemVenda();
        $persistenciaPessoa = new PersistenciaPessoa();
        $persistenciaProduto = new PersistenciaProduto();

        $this->ViewItemVenda = new ViewItemVenda();

        if (isset($_GET['consulta'])) {
            $select = $this->PersistenciaItemVenda->selectItemVenda();
            $selectItemVendas = $this->PersistenciaItemVenda->selectItemVendaTabela();
            foreach ($selectItemVendas as $value) {
             $select = $this->PersistenciaItemVenda->selectItemVenda($value[0]);   
             $totalItemVenda= $this->PersistenciaItemVenda->calculaTotalItemVenda($value[0]);   
             $this->ViewItemVenda->criarPaginaItemVendaExibir($select,$totalItemVenda);
            }
        } else if (isset($_GET['deletar'])) {
            $selectProduto = $persistenciaProduto->select();
            $selectPessoa = $persistenciaPessoa->select();
            $this->ViewItemVenda->criarPaginaItemVendaCadastrar($selectPessoa, $selectProduto);
            $this->deletar();
        } else if (isset($_GET['alterar'])) {
            $this->PersistenciaItemVenda->setCondicao($_GET['alterar']);
            $select = $this->PersistenciaItemVenda->selectItemVenda();
            $selectProduto = $persistenciaProduto->select();
            $selectPessoa = $persistenciaPessoa->select();

            $this->ViewItemVenda->criarPaginaItemVendaAlterar($select, $selectPessoa, $selectProduto);
            $this->alterar();
        } else if (isset($_GET['vizualizar'])) {
            $this->PersistenciaItemVenda->setCondicao($_GET['vizualizar']);
            $select = $this->PersistenciaItemVenda->selectItemVenda();
            $selectProduto = $persistenciaProduto->select();
            $selectPessoa = $persistenciaPessoa->select();

            $this->ViewItemVenda->criarPaginaItemVendaVizualizar($select, $this->verificaPessoa($selectPessoa, $select[0][2]), $this->verificaProduto($selectProduto, $select[0][1]));
        } else {
            $selectProduto = $persistenciaProduto->select();
            $selectPessoa = $persistenciaPessoa->select();

            $this->ViewItemVenda->criarPaginaItemVendaCadastrar($selectPessoa, $selectProduto);
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

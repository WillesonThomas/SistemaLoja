<?php

require_once 'model/ModelProduto.inc';
require_once './persistencia/PersistenciaProduto.inc';
require_once './view/ViewProduto.inc';

/**
 * Controller do Produto
 * @package controller
 * @author Willeson Thomas da Silva <will.thomassilva@gmail.com>
 */
class ControllerProduto {

    /** @var ModelProduto */
    private $Produto;

    /** @var PersistenciaProduto */
    private $PersistenciaProduto;

    /** @var ViewProduto */
    private $ViewProduto;

    public function __construct() {
        $this->processarDados();
    }

    function getProduto() {
        return $this->Produto;
    }

    function setProduto(ModelProduto $Produto) {
        $this->Produto = $Produto;
    }

    function getPersistenciaProduto() {
        return $this->PersistenciaProduto;
    }
    
    /**
     * Realiza o Processamento dos dados e verifica qual a��o execultar.
     */
    protected function processarDados() {
        $oProduto = new ModelProduto();
        $this->setProduto($oProduto);
        $this->PersistenciaProduto = new PersistenciaProduto();
        $this->ViewProduto = new ViewProduto();
        $this->verificaAcao();
    }

    /**
     * Realiza altera��es com base no produto selecionado na tabela 
     */
    protected function alterar() {
        $this->PersistenciaProduto->setCondicao($_GET['alterar']);
        $select = $this->PersistenciaProduto->select();
        $this->ViewProduto->criarPaginaProdutoAlterar($select);
        if (isset($_POST['descricao']) and !empty($_POST['preco'])) {
            $this->getProduto()->setCodigo($_GET['alterar']);
            $this->getProduto()->setDescricao($_POST['descricao']);
            $this->getProduto()->setPreco($_POST['preco']);
            $this->PersistenciaProduto->update($this->Produto);
        }
    }

    /**
     * Realiza cadastro do Produto com seus respectivos valores
     */
    protected function cadastrar() {
        $this->ViewProduto->criarPaginaProdutoCadastrar();
        if (isset($_POST['descricao']) and !empty($_POST['preco'])) {
            $this->getProduto()->setDescricao($_POST['descricao']);
            $this->getProduto()->setPreco($_POST['preco']);
            $this->PersistenciaProduto->insert($this->Produto);
        }
    }

    /**
     * Realiza Consulta no Banco de dados para exibir os dados na tela
     */
    protected function consultar() {
        $select = $this->PersistenciaProduto->select();
        $this->ViewProduto->criarPaginaProdutoExibir($select);
    }

    /**
     * Exibe as informa��es no produto em uma tela do formulario
     */
    protected function visualizar() {
        $this->PersistenciaProduto->setCondicao($_GET['visualizar']);
        $select = $this->PersistenciaProduto->select();
        $this->ViewProduto->criarPaginaProdutoVisualizar($select);
    }

    /**
     * Verifica as a��es com base nos par�metros
     */
    protected function verificaAcao() {
        switch (true) {
            case isset($_GET['consulta']):
                $this->consultar();
                break;
            case isset($_GET['alterar']):
                $this->alterar();
                break;
            case isset($_GET['visualizar']):
                $this->visualizar();
                break;
            default:
                $this->cadastrar();
                break;
        }
    }

}

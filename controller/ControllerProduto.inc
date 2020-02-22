<?php

require_once 'model/Produto.inc';
require_once './persistencia/PersistenciaProduto.inc';
require_once './view/ViewProduto.inc';

class ControllerProduto {

    /** @var Produto */
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

    function setProduto(Produto $Produto) {
        $this->Produto = $Produto;
    }
    
    function getPersistenciaProduto() {
        return $this->PersistenciaProduto;
    }
    
    public function alterar() {
        if ($this->validarCampos()) {
            $this->getProduto()->setCodigo($_GET['alterar']);
            $this->getProduto()->setDescricao($_POST['descricao']);
            $this->getProduto()->setPreco($_POST['preco']);
            $this->PersistenciaProduto->update($this->Produto);
        }
    }

    public function deletar() {
        $this->getProduto()->setCodigo($_GET['deletar']);
        $this->PersistenciaProduto->delete($this->Produto);
    }

    public function cadastrar() {
        if ($this->validarCampos()) {
            $this->getProduto()->setDescricao($_POST['descricao']);
            $this->getProduto()->setPreco($_POST['preco']);
            $this->PersistenciaProduto->insert($this->Produto);
        }
    }

    public function validarCampos() {
        if (isset($_POST['descricao']) and !empty($_POST['preco'])) {
            return true;
        }
        return false;
    }
    
    
    public function processarDados() {
        $oProduto = new Produto();
        $this->setProduto($oProduto);

        $this->PersistenciaProduto = new PersistenciaProduto();
        
        $this->ViewProduto = new ViewProduto();

        if (isset($_GET['consulta'])) {
            $select = $this->PersistenciaProduto->select();
            $this->ViewProduto->criarPaginaProdutoExibir($select);
        } else if (isset($_GET['deletar'])) {
            $this->ViewProduto->criarPaginaProdutoCadastrar();
            $this->deletar();
        } else if (isset($_GET['alterar'])) {
            $this->PersistenciaProduto->setCondicao($_GET['alterar']);
            $select = $this->PersistenciaProduto->select();
            $this->ViewProduto->criarPaginaProdutoAlterar($select);
            $this->alterar();
        } else if (isset($_GET['vizualizar'])) {
            $this->PersistenciaProduto->setCondicao($_GET['vizualizar']);
            $select = $this->PersistenciaProduto->select();
            $this->ViewProduto->criarPaginaProdutoVizualizar($select);            
        } else {
            $this->ViewProduto->criarPaginaProdutoCadastrar();
            $this->cadastrar();
        }
    }

}
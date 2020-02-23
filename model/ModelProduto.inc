<?php

/**
 * Model de Produto
 * @package model
 * @author Willeson Thomas da Silva <will.thomassilva@gmail.com>
 */
class ModelProduto {

    private $codigo;
    private $descricao;
    private $preco;

    function getPreco() {
        return $this->preco;
    }

    function setPreco($preco) {
        $this->preco = $preco;
    }
        
    function getCodigo() {
        return $this->codigo;
    }

    function getDescricao() {
        return $this->descricao;
    }

    function setCodigo($codigo) {
        $this->codigo = $codigo;
    }

    function setDescricao($descricao) {
        $this->descricao = $descricao;
    }

}
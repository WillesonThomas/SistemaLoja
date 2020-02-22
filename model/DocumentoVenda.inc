<?php

class DocumentoVenda {
    
    private $codigoVenda;
    private $total;
    private $situacao;
    
    function getCodigoVenda() {
        return $this->codigoVenda;
    }

    function getTotal() {
        return $this->total;
    }
    
    function getSituacao() {
        return $this->situacao;
    }

    function setCodigoVenda($codigoVenda) {
        $this->codigoVenda = $codigoVenda;
    }

    function setTotal($total) {
        $this->total = $total;
    }

    function setSituacao($situacao) {
        $this->situacao = $situacao;
    }

}
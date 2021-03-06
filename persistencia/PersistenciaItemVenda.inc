<?php

require_once 'Persistencia.inc';

class PersistenciaItemVenda {

    private $atributos;
    private $tabela;
    private $condicao;

    function getAtributos() {
        return $this->atributos;
    }

    function getTabela() {
        return $this->tabela;
    }

    function getCondicao() {
        return $this->condicao;
    }

    function setAtributos($atributos) {
        $this->atributos = $atributos;
    }

    function setTabela($tabela) {
        $this->tabela = $tabela;
    }

    function setCondicao($condicao) {
        $this->condicao = "TBITEM.DOCCODIGO=" . $condicao;
    }

    /**
     * Realiza a Insert no banco 
     * @param ModelDocumentoVenda $oDocumento
     * @param ModelProduto        $produto
     */
    public function insert(ModelDocumentoVenda $oDocumento,ModelProduto $produto) {
        Persistencia::insertBD("TBITEM",
                ['DOCCODIGO', 'PROCODIGO'],
                [$oDocumento->getCodigoVenda(), $produto->getCodigo()]);
    }

    /**
     * Realiza a Select no banco 
     */
    public function select() {
        $this->atributos = ['TBITEM.DOCCODIGO', 'TBITEM.PROCODIGO'];
        $this->tabela = 'TBITEM';
        if ($this->condicao == null) {
            return Persistencia::selectecBD($this->getAtributos(), $this->getTabela());
        } else {
            return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());
        }
    }
}
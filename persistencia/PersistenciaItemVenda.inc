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

    public function insert(Produto $produto) {
        Persistencia::insertBD("TBITEM",
                ['PRODESCRICAO', 'PROFABRICANTE','PROPRECOVENDA'],
                ['\'' . $produto->getDescricao() . '\'', '\'' .$produto->getFabricante(). '\'',$produto->getPrecoVenda()]);
    }

//    public function update(Produto $produto) {
//        Persistencia::updateBD("TBITEM",
//                ['DOCCODIGO=\'' . $produto->getDescricao() . '\'', 'PROFABRICANTE=\'' . $produto->getFabricante(). '\'', 'PROPRECOVENDA='.$produto->getPrecoVenda()],
//                 'PROCODIGO=' . $produto->getCodigo());
//    }
//
//    public function delete(Produto $produto) {
//        Persistencia::deleteBD("TBITEM", 'PROCODIGO=' . $produto->getCodigo());
//    }

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

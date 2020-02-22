<?php

require_once 'Persistencia.inc';

class PersistenciaProduto {

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
        $this->condicao = "TBPRODUTO.PROCODIGO=" . $condicao;
    }

    public function insert(Produto $produto) {
        Persistencia::insertBD("TBPRODUTO",
                ['PRODESCRICAO','PROPRECO'],
                ['\'' . $produto->getDescricao() . '\'',$produto->getPreco()]);
    }

    public function update(Produto $produto) {
        Persistencia::updateBD("TBPRODUTO",
                ['PRODESCRICAO=\'' . $produto->getDescricao() . '\'', 'PROPRECO='.$produto->getPreco()],
                 'PROCODIGO=' . $produto->getCodigo());
    }

    public function delete(Produto $produto) {
        Persistencia::deleteBD("TBPRODUTO", 'PROCODIGO=' . $produto->getCodigo());
    }

    public function select() {
        $this->atributos = ['TBPRODUTO.PROCODIGO', 'TBPRODUTO.PRODESCRICAO', 'TBPRODUTO.PROPRECO'];
        $this->tabela = 'TBPRODUTO';
        if ($this->condicao == null) {
            return Persistencia::selectecBD($this->getAtributos(), $this->getTabela());
        } else {
            return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());
        }
    }
}

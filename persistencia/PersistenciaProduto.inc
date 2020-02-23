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

    /**
     * Realiza a Insert no banco 
     * @param ModelProduto $produto
     */
    public function insert(ModelProduto $produto) {
        Persistencia::insertBD("TBPRODUTO",
                ['PRODESCRICAO','PROPRECO'],
                ['\'' . $produto->getDescricao() . '\'',$produto->getPreco()]);
    }

    /**
     * Realiza a Update no banco 
     * @param ModelProduto $produto
     */
    public function update(ModelProduto $produto) {
        Persistencia::updateBD("TBPRODUTO",
                ['PRODESCRICAO=\'' . $produto->getDescricao() . '\'', 'PROPRECO='.$produto->getPreco()],
                 'PROCODIGO=' . $produto->getCodigo());
    }

    /**
     * Realiza Delete no banco 
     * @param ModelProduto $produto
     */
    public function delete(ModelProduto $produto) {
        Persistencia::deleteBD("TBPRODUTO", 'PROCODIGO=' . $produto->getCodigo());
    }

    /**
     * Realiza a Select no banco 
     */
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

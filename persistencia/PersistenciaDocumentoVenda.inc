<?php

require_once 'Persistencia.inc';

class PersistenciaDocumentoVenda {

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
        $this->condicao = "TBDOCUMENTO.DOCCODIGO=" . $condicao;
    }

    /**
     * Realiza a Insert no banco 
     * @param ModelDocumentoVenda $docVenda
     */
    public function insert(ModelDocumentoVenda $docVenda) {
        Persistencia::insertBD("TBDOCUMENTO", ['DOCCODIGO', 'DOCTOTAL', 'DOCSITUACAO'],
                [$docVenda->getCodigoVenda(), $docVenda->getTotal(), $docVenda->getSituacao()]);
    }

    /**
     * Realiza a Update no banco 
     * @param ModelDocumentoVenda $docVenda
     */
    public function update(ModelDocumentoVenda $docVenda) {
        Persistencia::updateBD("TBDOCUMENTO",
                ['DOCTOTAL=' . $docVenda->getTotal(), 'DOCSITUACAO=' . $docVenda->getSituacao()],
                'DOCCODIGO=' . $docVenda->getCodigoVenda());
    }

    /**
     * Realiza a Update da situação no banco 
     * @param ModelDocumentoVenda $docVenda
     */
    public function updateSituacao(ModelDocumentoVenda $docVenda) {
        Persistencia::updateBD("TBDOCUMENTO",
                ['DOCSITUACAO=' . $docVenda->getSituacao()],
                'DOCCODIGO=' . $docVenda->getCodigoVenda());
    }

    /**
     * Realiza Delete no banco 
     * @param ModelDocumentoVenda $docVenda
     */
    public function delete(ModelDocumentoVenda $docVenda) {
        Persistencia::deleteBD("TBDOCUMENTO", 'DOCCODIGO=' . $docVenda->getCodigoVenda());
    }

    /**
     * Realiza a Select no banco 
     * @param String $condicao
     */
    public function selectDocumentoVenda($condicao = null) {
        $this->atributos = ['TBDOCUMENTO.DOCCODIGO', 'TBDOCUMENTO.DOCTOTAL', 'TBDOCUMENTO.DOCSITUACAO'];
        $this->tabela = 'TBDOCUMENTO';
        if ($condicao) {
            $this->condicao = 'TBDOCUMENTO.DOCCODIGO=' . $condicao;
        }
        return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());
    }

    /**
     * Realiza a Select filtrando pelas vendas confirmadas (DOCSITUAÇÃO = 1) o banco 
     */
    public function selectDocumentoVendaConfirmadas() {
        $this->atributos = ['TBDOCUMENTO.DOCCODIGO', 'TBDOCUMENTO.DOCTOTAL'];
        $this->tabela = 'TBDOCUMENTO';
        $this->condicao = 'TBDOCUMENTO.DOCSITUACAO=1';
        return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());
    }

    /**
     * Realiza a Select buscando o codigo da ultima venda cadastrada
     */
    public function getCodigoDocumentoVenda() {
        $this->atributos = ['TBDOCUMENTO.DOCCODIGO', 'TBDOCUMENTO.DOCTOTAL', 'TBDOCUMENTO.DOCSITUACAO'];
        $this->tabela = 'TBDOCUMENTO ORDER BY DOCCODIGO DESC LIMIT 1';
        return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());
    }

    /**
     * Realiza a Select no banco para calcular o total das vendas 
     * @param String $condicao
     */
    public function calculaTotalDocumentoVenda($condicao = null) {
        $this->atributos = ['SUM(DOCTOTAL)'];
        $this->tabela = 'TBDOCUMENTO';
        if ($condicao) {
            $this->condicao = 'TBDOCUMENTO.DOCSITUACAO=' . $condicao;
        }
        return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());
    }

}
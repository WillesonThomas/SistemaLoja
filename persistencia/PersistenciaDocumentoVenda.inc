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

    public function insert(DocumentoVenda $docVenda) {
        Persistencia::insertBD("TBDOCUMENTO", ['DOCCODIGO','DOCTOTAL', 'DOCSITUACAO'],
                [$docVenda->getCodigoVenda(), $docVenda->getTotal(), $docVenda->getSituacao()]);
    }

    public function update(DocumentoVenda $docVenda) {
        Persistencia::updateBD("TBDOCUMENTO",
                ['DOCTOTAL=' . $docVenda->getTotal(),'DOCSITUACAO=' . $docVenda->getSituacao()],
                 'DOCCODIGO=' . $docVenda->getCodigoVenda());
    }

    public function updateSituacao(DocumentoVenda $docVenda) {
        Persistencia::updateBD("TBDOCUMENTO",
                ['DOCSITUACAO=' . $docVenda->getSituacao()],
                 'DOCCODIGO=' . $docVenda->getCodigoVenda());
    }

    public function delete(DocumentoVenda $docVenda) {
        Persistencia::deleteBD("TBDOCUMENTO", 'DOCCODIGO=' . $docVenda->getCodigoVenda());
    }

    public function selectDocumentoVenda($condicao=null) {
        $this->atributos = ['TBDOCUMENTO.DOCCODIGO','TBDOCUMENTO.DOCTOTAL','TBDOCUMENTO.DOCSITUACAO'];
        $this->tabela = 'TBDOCUMENTO';
        if($condicao){
            $this->condicao = 'TBDOCUMENTO.DOCCODIGO='.$condicao;
        }
        return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());
    }

    public function selectDocumentoVendaConfirmadas() {
        $this->atributos = ['TBDOCUMENTO.DOCCODIGO','TBDOCUMENTO.DOCTOTAL'];
        $this->tabela = 'TBDOCUMENTO';
        $this->condicao = 'TBDOCUMENTO.DOCSITUACAO=1';
        return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());
    }

    public function getCodigoDocumentoVenda() {
        $this->atributos = ['TBDOCUMENTO.DOCCODIGO','TBDOCUMENTO.DOCTOTAL','TBDOCUMENTO.DOCSITUACAO'];
        $this->tabela = 'TBDOCUMENTO ORDER BY DOCCODIGO DESC LIMIT 1';
        return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());
    }
    
    public function calculaTotalDocumentoVenda($condicao=null){
        $this->atributos = ['SUM(DOCTOTAL)'];
        $this->tabela = 'TBDOCUMENTO';
        if($condicao){
            $this->condicao = 'TBDOCUMENTO.DOCSITUACAO='.$condicao;
        }
        return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());        
    }

}
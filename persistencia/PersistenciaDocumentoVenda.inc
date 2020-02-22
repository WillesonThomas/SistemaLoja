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
        Persistencia::insertBD("TBDOCUMENTO", ['DOCCODIGO','DOCTOTAL', 'DOCCONFIRMADO'],
                [$docVenda->getCodigoVenda(), $docVenda->getTotal(), $docVenda->getConfirmado()]);
    }

    public function update(DocumentoVenda $docVenda) {
        Persistencia::updateBD("TBDOCUMENTO",
                ['DOCTOTAL=' . $docVenda->getTotal(),'DOCCONFIRMADO=' . $docVenda->getConfirmado()],
                 'DOCCODIGO=' . $docVenda->getCodigoVenda());
    }

    public function delete(DocumentoVenda $docVenda) {
        Persistencia::deleteBD("TBDOCUMENTO", 'DOCCODIGO=' . $docVenda->getCodigoVenda());
    }

    public function selectDocumentoVenda($condicao=null) {
        $this->atributos = ['TBDOCUMENTO.DOCCODIGO','TBDOCUMENTO.DOCTOTAL','TBDOCUMENTO.DOCCONFIRMADO'];
        $this->tabela = 'TBDOCUMENTO';
        if($condicao){
            $this->condicao = 'TBDOCUMENTO.DOCCODIGO='.$condicao;
        }
        return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());
    }

    public function selectDocumentoVendaTabela() {
        $this->atributos = ['TBDOCUMENTO.DOCCODIGO'];
        $this->tabela = 'TBDOCUMENTO GROUP BY TBDOCUMENTO.DOCCODIGO';
        return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());
    }
    
//    public function calculaTotalDocumentoVenda($condicao){
//        $this->atributos = ['SUM((PEDQUANTIDADE*PEDPRECOUNITARIO)-PEDDESCONTO)'];
//        $this->tabela = 'TBDOCUMENTO';
//        $this->condicao = 'TBDOCUMENTO.PEDCODIGO='.$condicao;
//        return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());        
//    }

}

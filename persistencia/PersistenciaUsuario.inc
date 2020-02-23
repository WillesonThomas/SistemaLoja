<?php

require_once 'Persistencia.inc';

class PersistenciaUsuario {

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
     * Realiza a Select no banco 
     */
    public function select() {
        $this->atributos = ['TBUSUARIO.USACODIGO', 'TBUSUARIO.USAUSUARIO', 'TBUSUARIO.USASENHA', 'TBUSUARIO.USATIPO'];
        $this->tabela = 'TBUSUARIO';
        if ($this->condicao == null) {
            return Persistencia::selectecBD($this->getAtributos(), $this->getTabela());
        } else {
            return Persistencia::selectecBD($this->getAtributos(), $this->getTabela(), $this->getCondicao());
        }
    }
}

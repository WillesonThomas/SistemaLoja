<?php

require_once './persistencia/Persistencia.inc';

class Usuario {

    /** @var Persistencia */
    private $Estrutura;
    private $codigo;
    private $usuario;
    private $senha;
    
    function getEstrutura() {
        return $this->Estrutura;
    }

    function getCodigo() {
        return $this->codigo;
    }

    function getUsuario() {
        return $this->usuario;
    }

    function getSenha() {
        return $this->senha;
    }

    function setEstrutura(Persistencia $Estrutura) {
        $this->Estrutura = $Estrutura;
    }

    function setCodigo($codigo) {
        $this->codigo = $codigo;
    }

    function setUsuario($usuario) {
        $this->usuario = $usuario;
    }

    function setSenha($senha) {
        $this->senha = $senha;
    }
 
    //Valida os dados para efetuar login.
    public static function validarLogin() {
        $atributosSelect = ['TBUSUARIO.USAUSUARIO', 'TBUSUARIO.USASENHA', 'TBUSUARIO.USATIPO'];
        $tabela = 'TBUSUARIO';
        foreach (Persistencia::selectecBD($atributosSelect, $tabela) as $value) {
            if ($value[0] == ($_POST['usuario']) and $value[1] == md5(($_POST['senha']))) {
                $_SESSION['usuarioSecao'] = $_POST['usuario'];
                $_SESSION['usuarioTipo']  = $value[2];
                header("Location: paginaPrincipalUsuario.php");
            }
        }
    }
}


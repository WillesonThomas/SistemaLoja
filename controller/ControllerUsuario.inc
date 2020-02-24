<?php

require_once './model/ModelUsuario.inc';
require_once './persistencia/PersistenciaUsuario.inc';

/**
 * Controller do Usuario
 * @package controller
 * @author Willeson Thomas da Silva <will.thomassilva@gmail.com>
 */
class ControllerUsuario {

    /** @var ModelUsuario */
    private $Usuario;

    /** @var PersistenciaUsuario */
    private $PersistenciaUsuario;

    public function __construct() {
        $this->processarDados();
    }

    function getUsuario() {
        return $this->Usuario;
    }

    function setUsuario(ModelUsuario $Usuario) {
        $this->Usuario = $Usuario;
    }
    
    /**
     * Realiza o Processamento dos dados e verifica qual ação execultar.
     */
    protected function processarDados() {
        $oUsuario = new ModelUsuario();
        $this->setUsuario($oUsuario);
        $this->getUsuario()->setUsuario($_POST['usuario']);
        $this->getUsuario()->setSenha(md5(($_POST['senha'])));
        $this->PersistenciaUsuario = new PersistenciaUsuario();
        $this->validarLogin();
    }
    
    /**
     * Realiza Validação dos dados para efetuar login
     */
    protected function validarLogin() {
        $select = $this->PersistenciaUsuario->select();
        foreach ($select as $value) {
            if ($value[1] == $this->getUsuario()->getUsuario() and $value[2] == $this->getUsuario()->getSenha()) {
                $_SESSION['usuarioSecao'] = $_POST['usuario'];
                $_SESSION['usuarioTipo'] = $value[3];
                header("Location: paginaPrincipalUsuario.php");
            }
        }
    }

}
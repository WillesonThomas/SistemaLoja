<?php

require_once './view/ViewPaginaPrincipalUsuario.inc';

class ControllerPaginaPrincipal {

    /** @var ViewPaginaPrincipalUsuario */
    private $ViewPaginaPrincipalUsuario;

    public function __construct() {
        $this->ViewPaginaPrincipalUsuario = new ViewPaginaPrincipalUsuario();
        $this->ViewPaginaPrincipalUsuario->criarPaginaPrincipalUsuario();
    }

}

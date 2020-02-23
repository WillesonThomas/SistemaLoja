<?php

require_once './view/ViewPaginaPrincipalUsuario.inc';

/**
 * Controller da Pagina Principal
 * @package controller
 * @author Willeson Thomas da Silva <will.thomassilva@gmail.com>
 */
class ControllerPaginaPrincipal {

    /** @var ViewPaginaPrincipalUsuario */
    private $ViewPaginaPrincipalUsuario;

    public function __construct() {
        $this->ViewPaginaPrincipalUsuario = new ViewPaginaPrincipalUsuario();
        $this->ViewPaginaPrincipalUsuario->criarPaginaPrincipalUsuario();
    }

}

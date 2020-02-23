<?php

require_once './model/ModelEstrutura.inc';

/**
 * View da Pagina Principal do Usuario
 * @package view
 * @author Willeson Thomas da Silva <will.thomassilva@gmail.com>
 */
class ViewPaginaPrincipalUsuario {
    
    /**
     * Cria Pagina principal do usuario
     */
    public function criarPaginaPrincipalUsuario(){
        ModelEstrutura::criarPaginaIncial();
    }
}

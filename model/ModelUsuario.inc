<?php

/**
 * Model de Usuario
 * @package model
 * @author Willeson Thomas da Silva <will.thomassilva@gmail.com>
 */
class ModelUsuario {

    private $codigo;
    private $usuario;
    private $senha;
    private $tipo;

    function getCodigo() {
        return $this->codigo;
    }

    function getUsuario() {
        return $this->usuario;
    }

    function getSenha() {
        return $this->senha;
    }

    function getTipo() {
        return $this->tipo;
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

    function setTipo($tipo) {
        $this->tipo = $tipo;
    }

}
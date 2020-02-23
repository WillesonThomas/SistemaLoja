<?php

class Persistencia {

    private static function conexao() {
        $sHost = 'localhost';
        $sPort = '3306';
        $sDbName = 'LOJA';
        $sUser = 'root';
        $sPassword = '';

        $sConexao = mysqli_connect($sHost, $sUser, $sPassword, $sDbName);
        if (!$sConexao) {
            die("Connection failed: " . mysqli_connect_error());
        }
        return $sConexao;
    }

    public static function selectecBD($arrayAtributos, $elementosTabela, $condicao = null) {
        $select = ' ';
        $atributos = ' SELECT ';
        $tabela = ' FROM ';
        $where = ' WHERE ';
        for ($index = 0; $index < count($arrayAtributos); $index++) {
            $atributos .= $arrayAtributos[$index];
            if ((count($arrayAtributos) - 1) != $index) {
                $atributos .= ',';
            }
        }
        $tabela .= $elementosTabela;
        if ($condicao == null) {
            $select .= $atributos . $tabela;
        } else {
            $where .= $condicao;
            $select .= $atributos . $tabela . $where;
        }
        return self::montarSQL($select);
    }

    public static function insertBD($tabela, $arrayAtributos, $valoresTabela) {
        $insert = ' ';
        $atributos = ' INSERT INTO ' . $tabela . ' (';
        $valores = ' VALUES (';
        for ($index = 0; $index < count($arrayAtributos); $index++) {
            $atributos .= $arrayAtributos[$index];
            if ((count($arrayAtributos) - 1) != $index) {
                $atributos .= ',';
            } else {
                $atributos .= ') ';
            }
        }
        for ($index1 = 0; $index1 < count($valoresTabela); $index1++) {
            $valores .= $valoresTabela[$index1];
            if ((count($valoresTabela) - 1) != $index1) {
                $valores .= ',';
            } else {
                $valores .= ');';
            }
        }
        $insert .= $atributos . $valores;
        mysqli_query(self::conexao(), $insert);
        mysqli_close(self::conexao());
    }

    public static function updateBD($tabela, $arraySets, $condicao) {
        $update = ' ';
        $updateTabela = ' UPDATE ' . $tabela;
        $valores = ' SET ';
        $updateCondicao = ' ';
        for ($index1 = 0; $index1 < count($arraySets); $index1++) {
            $valores .= $arraySets[$index1];
            if ((count($arraySets) - 1) != $index1) {
                $valores .= ',';
            }
        }
        $updateCondicao .= ' WHERE ' . $condicao;
        $update .= $updateTabela . $valores . $updateCondicao;
        mysqli_query(self::conexao(), $update);
        mysqli_close(self::conexao());
    }

    public static function deleteBD($tabela, $condicao = null) {
        $delete = ' ';
        $deleteAtributos = 'DELETE ';
        $deleteTabela = ' FROM ' . $tabela;
        $deleteWhere = ' WHERE ';
        if ($condicao == null) {
            $delete .= $deleteAtributos . $deleteTabela;
        } else {
            $deleteWhere .= $condicao;
            $delete .= $deleteAtributos . $deleteTabela . $deleteWhere;
        }
        mysqli_query(self::conexao(), $delete);
        mysqli_close(self::conexao());
    }

    private static function montarSQL($select) {
        $aVetor = array();
        $aResultado = mysqli_fetch_all(mysqli_query(self::conexao(), $select));
        foreach ($aResultado as $value) {
            $aVetor[] = $value;
        }
        return $aVetor;
    }

}

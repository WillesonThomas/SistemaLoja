<?php

/**
 * Persistencia
 * @package persistencia
 * @author Willeson Thomas da Silva <will.thomassilva@gmail.com>
 */
class Persistencia {

    /**
     * Realiza a conexão com o banco de dados
     */
    private static function conexao() {
        $oConfig = self::lerConfiguracaoXml();
        $sHost     = $oConfig[0];
        $sDbName   = $oConfig[1];
        $sUser     = $oConfig[2];
        $sPassword = $oConfig[3];

        $sConexao = mysqli_connect($sHost, $sUser, $sPassword, $sDbName);
        if (!$sConexao) {
            die("Connection failed: " . mysqli_connect_error());
        }
        return $sConexao;
    }

    /**
     * Realiza a leitura de configuração do xml para conexão com o banco de dados
     * @return Array $aElementos
     */
    private static function lerConfiguracaoXml() {
        $xml = simplexml_load_file('configuracao.xml');
        $aElementos = [$xml->host, $xml->banco, $xml->user, $xml->password];
        return $aElementos;
    }

    /**
     * Realiza a select no banco com base nos parâmetros 
     * @param Array   $arrayAtributos
     * @param Array   $elementosTabela
     * @param boolean $condicao
     */
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

    /**
     * Realiza a Insert no banco com base nos parâmetros 
     * @param String  $tabela
     * @param Array   $arrayAtributos
     * @param Array $valoresTabela
     */
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

    /**
     * Realiza a Update no banco com base nos parâmetros 
     * @param String $tabela
     * @param Array  $arraySets
     * @param String $condicao
     */
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

    /**
     * Realiza a Delete no banco com base nos parâmetros 
     * @param String $tabela
     * @param String $condicao
     */
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

    /**
     * Realiza a montagem do SQL e retorna os valores 
     * @param  String $select
     * @return Array  $aVetor
     */
    private static function montarSQL($select) {
        $aVetor = array();
        $aResultado = mysqli_fetch_all(mysqli_query(self::conexao(), $select));
        foreach ($aResultado as $value) {
            $aVetor[] = $value;
        }
        return $aVetor;
    }

}

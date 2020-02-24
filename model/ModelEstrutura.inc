<?php

/**
 * Model da Estrutura
 * @package model
 * @author Willeson Thomas da Silva <will.thomassilva@gmail.com>
 */
class ModelEstrutura {

    /**
     * Realiza o carregamento da pagina
     */
    public static function carregarPagina($get) {
        if (!include_once $get . '.inc') {
            session_destroy();
            echo 'Destruida';
            header("Location: paginaLogin.php");
        }
    }

    /**
     * Realiza a criação da pagina principal
     */
    public static function criarPaginaPrincipal() {
        ?>
        <div class="containerBanner">

        </div>      
        </div>;
        <?php
    }

    /**
     * Realiza a criação da pagina inicial
     */
    public static function criarPaginaIncial() {
        ?>
        <div id="divGradeImg">
            <div style="text-align:center">
                <h2>Menu</h2>
            </div>
            <div class="row menu-grid">
                <div class="column menu-column">
                    <h3>Produtos</h3>
                    <a href="paginaPrincipalUsuario.php?pg=ViewProduto&consulta">
                        <img src="imagens/imgProduto.png"/>
                    </a>
                </div>
                <?php
                if (isset($_SESSION['usuarioTipo']) and ($_SESSION['usuarioTipo']) == 0) {
                    echo '<div class="column menu-column">
                    <h3>Vendas</h3>
                    <a href="paginaPrincipalUsuario.php?pg=ViewDocumentoVenda&consulta">
                        <img src="imagens/imgVenda.png"/>
                    </a>
                    </div>';
                }
                ?>
            </div>

            <div class="containerTabelaImagens">
                <span onclick="this.parentElement.style.display = \'none\'" class="closebtn">&times;</span>
                <img id="expandedImg" style="width:100%">
                <div id="imgtext"></div>
            </div>        
        </div>
        <?php
    }

    /**
     * Realiza a criação do menu do cliente
     */
    public static function criarMenuCliente() {
        ?>
        <div class="navbar">
            <a href="paginaPrincipalCliente.php">Pagina Inicial</a>
            <a id="sessao" href="paginaLogin.php">Login</a></div>
        <?php
    }

    /**
     * Realiza a criação do menu
     */
    public static function criarMenu() {
        ?>
        <div class="navbar">
            <a href="paginaPrincipalUsuario.php">Pagina Inicial</a>
            <div class="subnav">
                <button class="subnavbtn">Exibir <i class="fa fa-caret-down"></i></button>
                <div class="subnav-content">
                    <?php
                    echo '<a href="paginaPrincipalUsuario.php?pg=ViewProduto&consulta">Produto</a>';
                    if (isset($_SESSION['usuarioTipo']) and ($_SESSION['usuarioTipo']) == 0) {
                        echo '<a href="paginaPrincipalUsuario.php?pg=ViewDocumentoVenda&consulta">Venda</a>';
                    }
                    ?>
                </div></div>

            <div class="subnav">
                <button class="subnavbtn">Cadastrar <i class="fa fa-caret-down"></i></button>
                <div class="subnav-content">
                    <?php
                    if (isset($_SESSION['usuarioTipo']) and ($_SESSION['usuarioTipo']) == 0) {
                        echo '<a href="paginaPrincipalUsuario.php?pg=ViewProduto">Produto</a>';
                    }
                    echo '<a href="paginaPrincipalUsuario.php?pg=ViewDocumentoVenda">Venda</a>';
                    ?>
                </div></div>'
            <a id="sessao" href="paginaLogin.php">Logout</a>
            <?php
            if (isset($_SESSION['usuarioSecao'])) {
                echo '<a id="sessao" href="">' . $_SESSION['usuarioSecao'] . '</a></div>';
            } else {
                header("Location: paginaLogin.php");
            }
        }

        /**
         * Realiza a criação dos avisos das paginas
         */
        public static function criarAviso() {
            ?>
            <div id="divAvisoAlerta">
                <span class="fechar" title="Close Modal">&times;</span>
                <img src="imagens/icones/alert.png" class="imagemAviso" alt="alerta"/>
                <br/>
                <div class="conteudoAviso">
                    <h3 class="mensagem" id="mensagemAvisoAlerta"></h3>
                </div>
            </div>

            <div id="divAvisoErro">
                <span class="fechar" title="Close Modal">&times;</span>
                <img src="imagens/icones/error.png" class="imagemAviso" alt="alerta"/>
                <br/>
                <div class="conteudoAviso">
                    <h3 class="mensagem" id="mensagemAvisoErro"></h3>
                </div>
            </div>

            <div id="divAvisoSucesso">
                <span class="fechar" title="Close Modal">&times;</span>
                <img src="imagens/icones/success.png" class="imagemAviso" alt="alerta"/>
                <br/>
                <div class="conteudoAviso">
                    <h3 class="mensagem" id="mensagemAvisoSucesso"></h3>
                </div>
            </div>            
            <div id="divInfo">
                <span class="fechar" title="Close Modal">&times;</span>
                <img src="imagens/icones/question.png" class="imagemAviso" alt="ajuda"/>
                <br/>
                <div class="conteudoAviso">
                    <h3 class="mensagem" id="mensagemInfo">
                        Todos os Campos devem ser Preenchidos<br>
                    </h3>
                </div>
            </div></div></div>
        <?php
    }

    /**
     * Realiza a criação do Formulário com suas respectivas ações e funcionalidades
     * @param String $acaoFormulario
     * @param String $tituloFormulario
     * @param boolean $method
     */
    public static function criarFormulario($acaoFormulario, $tituloFormulario, $method = false) {
        echo '<div id="formulario"><div class="container">';
        if ($method) {
            echo '<form action="' . $acaoFormulario . '" method="GET">';
        } else {
            echo '<form action="' . $acaoFormulario . '" method="POST">';
        }
        echo '<h1>' . $tituloFormulario . '</h1><hr>';
    }

    /**
     * Realiza a criação de tipos de input com base nos parâmetros
     * @param String $idAlerta
     * @param String $name
     * @param String $label
     * @param String $idCampo
     * @param String $typeCampo
     * @param int    $tamanhoMax
     * @param boolean $value
     * @param boolean $desabilitar
     * @param boolean $verifica
     * @param boolean $readOnly
     */
    public static function criarInput($idAlerta, $name, $label, $idCampo, $typeCampo, $tamanhoMax, $value = false, $desabilitar = false, $verifica = false, $readOnly = false) {
        echo '<img src="imagens/icones/error.png" id="' . $idAlerta . '" class="imagemalertasmall"/>'
        . '<label for="' . $name . '"><b>' . $label . '</b></label>';
        if ($desabilitar) {
            echo '<input id="' . $idCampo . '" type="' . $typeCampo . '" name="' . $name . '" maxlength="' . $tamanhoMax . '" value="' . $value . '" disabled required>';
        } else {
            if (!$value) {
                echo '<input id="' . $idCampo . '" type="' . $typeCampo . '" name="' . $name . '" maxlength="' . $tamanhoMax . '" required>';
            } else if ($readOnly == true and $value == true) {
                echo '<input id="' . $idCampo . '" type="' . $typeCampo . '" name="' . $name . '" maxlength="' . $tamanhoMax . '" value="' . $value . '" readonly="readonly" required>';
            } else {
                echo '<input id="' . $idCampo . '" type="' . $typeCampo . '" name="' . $name . '" maxlength="' . $tamanhoMax . '" value="' . $value . '" required>';
            }
        }
        if ($verifica) {
            echo '</form>';
            self::criarAviso();
        }
    }

    /**
     * Realiza a criação de tipos de Botão com base nos parâmetros
     * @param String $type
     * @param String $value
     * @param String $idButton
     * @param boolean $verifica
     */
    public static function criarBotao($type, $value, $idButton, $verifica = false) {
        $classBotao = "btnCadastrar";
        if ($type == "reset") {
            $classBotao = "btnLimpar";
        }
        echo '<input type="' . $type . '" class="' . $classBotao . '" value="' . $value . '" id="' . $idButton . '">';
        if ($verifica) {
            echo '</form>';
            self::criarAviso();
        }
    }

    /**
     * Realiza a criação de Select com base nos parâmetros
     * @param String $idAlerta
     * @param String $name
     * @param String $label
     * @param String $id
     * @param Array  $lista
     * @param boolean $verifica
     * @param boolean $verificaAlterar
     */
    public static function criarSelect($idAlerta, $name, $label, $id, $lista, $verifica = false, $verificaAlterar = false) {
        echo '<img src="imagens/icones/error.png" id="' . $idAlerta . '" class="imagemalertasmall"/>'
        . '<label for="' . $name . '"><b>' . $label . '*</b></label>';
        echo '<select class="campoSelect" name="' . $name . '" id="' . $id . '">';
        var_dump($lista);
        if (!$verificaAlterar) {
            echo '<option value=""></option>';
            foreach ($lista as $value) {
                echo '<option value="' . $value[0] . '">' . $value[1] . '</option>';
            }
        } else {
            foreach ($lista as $value) {
                echo 'entroi';
                if ($value[0] == $verificaAlterar) {
                    echo '<option value="' . $value[0] . '" selected>' . $value[1] . '</option>';
                } else {
                    echo '<option value="' . $value[0] . '">' . $value[1] . '</option>';
                }
            }
        }
        echo '</select>';
        if ($verifica) {
            echo '</form>';
            self::criarAviso();
        }
    }

    /**
     * Realiza Criação da Tabela
     * @param Array $colunas
     * @param Array $dados
     * @param boolean $verificaAcao
     * @param boolean $verificaAcaoAlterar
     */
    public static function montarTabela($colunas, $dados, $verificaAcao = false, $verificaAcaoAlterar = false) {
        echo '<br>';
        echo '<table border="1" class="table_listagem">';
        //montar titulos da tabela
        echo '<thead>';
        echo '<tr>';
        foreach ($colunas as $nomeColuna) {
            echo '<th>' . $nomeColuna . '</th>';
        }
        if (!$verificaAcao) {
            echo '<th>Acoes</th>';
        }
        echo '</tr>';
        echo '</thead>';
        echo '<tbody>';

        foreach ($dados as $oLinha) {
            echo '<tr>';
            $iAlterar = 0;
            $iVizualizar = 0;
            foreach ($oLinha as $index => $value) {
                if ($index == 0) {
                    $iAlterar = $value;
                    $iVizualizar = $value;
                }
                echo '<td>' . $value . '</td>';
            }
            if (!$verificaAcao) {
                echo '<td><a href="paginaPrincipalUsuario.php?pg=' . ($_GET['pg']) .
                '&alterar=' . $iAlterar . '"><img style="height:30px; padding-top:5px" class="iconesacoes" src="imagens/icones/pencil-icon.png" style="width:25px;height:25px"></a>';
                echo '<a href="paginaPrincipalUsuario.php?pg=' . ($_GET['pg']) .
                '&visualizar=' . $iVizualizar . '"><img class="iconesacoes" src="imagens/icones/eye-icon.png" style="width:25px;height:25px"></a>';
                echo '</td>';
            }
            echo '</tr>';
        }
        echo '</tbody>';
        echo '</table>';
    }

    /**
     * Realiza Criação da Tabela para ser Preenchida com dados retornados no Ajax
     */
    public static function montaTabelaJs() {
        ?>
        <br>
        <table border="1" class="table_listagem" id="itemList">
            <thead>
                <tr>
                    <td>Codigo</td>
                    <td>Descricao</td>
                    <td>Preco</td>
                </tr>
            </thead>
            <tbody>
            </tbody>
        </table>
        <?php
    }

}

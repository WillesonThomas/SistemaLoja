<?php

require_once './model/ModelEstrutura.inc'; //encerra se não achar

class ViewProduto {

    /**
     * Cria a Formulário de cadastro do Produto
     */
    public function criarPaginaProdutoCadastrar() {
        ModelEstrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewProduto", "Cadastro de Produto");
        ModelEstrutura::criarInput("alertaDescricao", "descricao", "Descricao", "campoDescricao", "text", "50");
        ModelEstrutura::criarInput("alertaPrecoVenda", "preco", "Preco", "campoPrecoVenda", "text", "50");
        ModelEstrutura::criarBotao("submit", "CADASTRAR", "cadastrar");
        ModelEstrutura::criarBotao("reset", "LIMPAR", "limpar", true);
    }

    /**
     * Cria a tabela de Produto
     * @param Array $select
     */
    public function criarPaginaProdutoExibir($select) {
        echo '<center><h1>Produto</h1></center>';
        echo '<div style="height:700px">';
        if (isset($_SESSION['usuarioTipo']) and ($_SESSION['usuarioTipo']) == 0) {
            ModelEstrutura::montarTabela(['Codigo Produto', 'Descricao', 'Preco'], $select);
        } else {
            ModelEstrutura::montarTabela(['Codigo Produto', 'Descricao', 'Preco'], $select, true, true);
        }
        echo '</div>';
    }

    /**
     * Cria a Formulário para alterar Produto
     * @param Array $selectProduto
     */
    public function criarPaginaProdutoAlterar($selectProduto) {
        ModelEstrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewProduto&alterar=" . ($_GET['alterar']), "Alterar Produto");
        ModelEstrutura::criarInput("alertaDescricao", "descricao", "Descricao", "campoDescricao", "text", "50", $selectProduto[0][1]);
        ModelEstrutura::criarInput("alertaPrecoVenda", "preco", "Preco", "campoPrecoVenda", "text", "50", $selectProduto[0][2]);
        ModelEstrutura::criarBotao("submit", "ALTERAR", "cadastrar");
        ModelEstrutura::criarBotao("reset", "LIMPAR", "limpar", true);
    }

    /**
     * Cria a Formulário para visualizar Produto
     * @param Array $selectProduto
     */
    public function criarPaginaProdutoVisualizar($selectProduto) {
        ModelEstrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewProduto&visualizar=" . ($_GET['visualizar']), "Visualizar Produto");
        ModelEstrutura::criarInput("alertaDescricao", "descricao", "Descricao", "campoDescricao", "text", "50", $selectProduto[0][1], true);
        ModelEstrutura::criarInput("alertaPrecoVenda", "preco", "Preco", "campoPrecoVenda", "text", "50", $selectProduto[0][2], true, true);
    }

}

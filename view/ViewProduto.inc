<?php

require_once './model/Estrutura.inc'; //encerra se não achar

class ViewProduto {
      public function criarPaginaProdutoCadastrar() {
        Estrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewProduto", "Cadastro de Produto");
        Estrutura::criarInput("alertaDescricao", "descricao", "Descricao", "campoDescricao", "text", "50");
        Estrutura::criarInput("alertaPrecoVenda", "preco", "Preco", "campoPrecoVenda", "text", "50");
        Estrutura::criarBotao("submit", "CADASTRAR", "cadastrarImovel");
        Estrutura::criarBotao("reset", "LIMPAR", "limparImovel", true);
    }

    public function criarPaginaProdutoExibir($select) {
        echo '<center><h1>Produto</h1></center>';
        echo '<div style="height:700px">';
        Estrutura::montarTabela(['Codigo Produto','Descricao', 'Preco'],$select);
        echo '</div>';
    }

    public function criarPaginaProdutoAlterar($selectProduto) {
        Estrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewProduto&alterar=" . ($_GET['alterar']), "Alterar Produto");
        Estrutura::criarInput("alertaDescricao", "descricao", "Descrição", "campoDescricao", "text", "50", $selectProduto[0][1]);
        Estrutura::criarInput("alertaPrecoVenda", "preco", "Preço", "campoPrecoVenda", "text", "50",$selectProduto[0][2]);
        Estrutura::criarBotao("submit", "ALTERAR", "cadastrarImovel");
        Estrutura::criarBotao("reset", "LIMPAR", "limparImovel", true);
    }  

    public function criarPaginaProdutoVizualizar($selectProduto) {
        Estrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewProduto&vizualizar=" . ($_GET['vizualizar']), "Vizualizar Produto");
        Estrutura::criarInput("alertaDescricao", "descricao", "Descrição", "campoDescricao", "text", "50", $selectProduto[0][1],true);
        Estrutura::criarInput("alertaPrecoVenda", "preco", "Preço", "campoPrecoVenda", "text", "50",$selectProduto[0][2],true,true);
    }  
}
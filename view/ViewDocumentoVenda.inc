<?php

require_once './model/Estrutura.inc'; //encerra se não achar

class ViewDocumentoVenda {
      public function criarPaginaDocumentoVendaCadastrar($selectPessoa,$selectProduto) {
        Estrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewDocumentoVenda", "Cadastro de DocumentoVenda");
        Estrutura::criarInput("alertaCodigoDocumentoVenda", "codigoDocumentoVenda", "DocumentoVenda", "campoCodigoDocumentoVenda", "text", "11");
        Estrutura::criarBotao("submit", "CADASTRAR", "cadastrarPessoaImovel");
        Estrutura::criarBotao("reset", "LIMPAR", "limparImovel", true);
    }

    public function criarPaginaDocumentoVendaExibir($select,$totalDocumentoVenda) {
        echo '<center><h1>Venda '.$select[0][6].'</h1></center>';
        echo '<div style="height:700px">';
        Estrutura::montarTabela(['Código','Total','Situação'],$select);
        echo '<center><h2>Total:'.$totalDocumentoVenda[0][0].'<h2></center>';
        echo '</div>';
        echo '<br><hr><br>';
    }

    public function criarPaginaDocumentoVendaAlterar($select,$selectPessoa,$selectProduto) {
        Estrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewDocumentoVenda&alterar=" . ($_GET['alterar']), "Alterar DocumentoVenda");
        Estrutura::criarInput("alertaCodigoDocumentoVenda", "codigoDocumentoVenda", "DocumentoVenda", "campoCodigoDocumentoVenda", "text", "11",$select[0][6]);
        Estrutura::criarSelect("alertaCodigoPessoa", "codigoPessoa", "Pessoa", "campoCodigoPessoa", $selectPessoa, null, $select[0][2]);
        Estrutura::criarSelect("alertaCodigoProduto", "codigoProduto", "Produto", "campoCodigoProduto", $selectProduto, null, $select[0][1]);
        Estrutura::criarInput("alertaQuantidade", "quantidade", "Quantidade", "campoQuantidade", "text", "50",$select[0][3]);
        Estrutura::criarInput("alertaPrecoUnitario", "precoUnitario", "Preco Unitario", "campoPrecoUnitario", "text", "50",$select[0][4]);
        Estrutura::criarInput("alertaDesconto", "desconto", "Desconto", "campoDesconto", "text", "50", $select[0][5]);
        Estrutura::criarBotao("submit", "ALTERAR", "cadastrarPessoaImovel");
        Estrutura::criarBotao("reset", "LIMPAR", "limparImovel", true);
    }

    public function criarPaginaDocumentoVendaVizualizar($select,$selectPessoa,$selectProduto) {
        Estrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewDocumentoVenda&vizualizarr=" . ($_GET['vizualizar']), "Vizualiar DocumentoVenda");
        Estrutura::criarInput("alertaCodigoDocumentoVenda", "codigoDocumentoVenda", "DocumentoVenda", "campoCodigoDocumentoVenda", "text", "11",$select[0][6],true);
        Estrutura::criarInput("alertaCodigoPessoa", "codigoPessoa", "Pessoa", "campoCodigoPessoa","text", "50", $selectPessoa, true);
        Estrutura::criarInput("alertaCodigoProduto", "codigoProduto", "Produto", "campoCodigoProduto","text", "50", $selectProduto, true);
        Estrutura::criarInput("alertaQuantidade", "quantidade", "Quantidade", "campoQuantidade", "text", "50",$select[0][3],true);
        Estrutura::criarInput("alertaPrecoUnitario", "precoUnitario", "Preco Unitario", "campoPrecoUnitario", "text", "50",$select[0][4],true);
        Estrutura::criarInput("alertaDesconto", "desconto", "Desconto", "campoDesconto", "text", "50", $select[0][5],true,true);
    }  
}

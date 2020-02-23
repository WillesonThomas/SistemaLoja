<?php

require_once './model/Estrutura.inc'; //encerra se não achar

class ViewDocumentoVenda {
    
      public function criarPaginaDocumentoVendaCadastrar($iCodigoProduto) {
        Estrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewDocumentoVenda", "Cadastro de Venda");
        Estrutura::criarInput("alertaCodigoDocumentoVenda", "codigoDocumentoVenda", "Codigo da Venda", "campoCodigoDocumentoVenda", "text", "11",$iCodigoProduto,false, false, true);
        Estrutura::criarInput("alertaCodigoProdutoDocumentoVenda", "codigoProdutoDocumentoVenda", "Codigo", "campoCodigoProdutoDocumentoVenda", "text", "11");
        Estrutura::criarBotao("button", "BUSCAR PRODUTO", "buscarProduto");
        echo '<br>';
        Estrutura::montaTabelaJs();
        echo '<br><br><br><br>';
        Estrutura::criarBotao("submit", "CONFIRMAR", "cadastrarPessoaImovel");
        Estrutura::criarBotao("reset", "CANCELAR", "limparImovel", true);
    }

    public function criarPaginaDocumentoVendaExibir($select,$totalDocumentoVenda) {
        echo '<center><h1>Vendas Confirmadas</h1></center>';
        echo '<div style="height:700px">';
        Estrutura::montarTabela(['Codigo da Venda','Total'],$select, true, true);
        echo '<center><h2>Total das Vendas: '.$totalDocumentoVenda[0][0].'<h2></center>';
        echo '</div>';
        echo '<br><hr><br>';
    }
    
}
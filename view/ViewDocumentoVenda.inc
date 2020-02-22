<?php

require_once './model/Estrutura.inc'; //encerra se não achar

class ViewDocumentoVenda {
    
      public function criarPaginaDocumentoVendaCadastrar($selectPessoa,$selectProduto) {
        Estrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewDocumentoVenda", "Cadastro de Venda Numero: ".'423');
        Estrutura::criarInput("alertaCodigoProdutoDocumentoVenda", "codigoProdutoDocumentoVenda", "Codigo", "campoCodigoProdutoDocumentoVenda", "text", "11");
        Estrutura::criarBotao("button", "BUSCAR", "buscarProduto");
        Estrutura::montaTabelaJs();
        Estrutura::criarBotao("submit", "CADASTRAR", "cadastrarPessoaImovel");
        Estrutura::criarBotao("reset", "LIMPAR", "limparImovel", true);
    }

    public function criarPaginaDocumentoVendaExibir($select,$totalDocumentoVenda) {
//        echo '<center><h1>Venda '.$select[0][0].'</h1></center>';
//        echo '<div style="height:700px">';
//        Estrutura::montarTabela(['Codigo','Total','Situacao'],$select);
//        echo '<center><h2>Total:'.$totalDocumentoVenda[0][2].'<h2></center>';
//        echo '</div>';
//        echo '<br><hr><br>';
    }

    public function criarPaginaDocumentoVendaAlterar($select,$selectPessoa,$selectProduto) {
//        Estrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewDocumentoVenda&alterar=" . ($_GET['alterar']), "Alterar DocumentoVenda");
//        Estrutura::criarInput("alertaCodigoDocumentoVenda", "codigoDocumentoVenda", "Codigo", "campoCodigoDocumentoVenda", "text", "11",$select[0][0]);
//        Estrutura::criarInput("alertaTotalDocumentoVenda", "totalDocumentoVenda", "Total", "campoTotalDocumentoVenda", "text", "50",$select[0][1]);
//        Estrutura::criarInput("alertaPrecoUnitario", "situacaoDocumentoVenda", "Situacao", "campoSituacaoDocumentoVenda", "text", "50",$select[0][2]);
//        Estrutura::criarBotao("submit", "ALTERAR", "cadastrarPessoaImovel");
//        Estrutura::criarBotao("reset", "LIMPAR", "limparImovel", true);
    }

    public function criarPaginaDocumentoVendaVizualizar($select,$selectPessoa,$selectProduto) {
//        Estrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewDocumentoVenda&vizualizarr=" . ($_GET['vizualizar']), "Visualiar Venda");
//        Estrutura::criarInput("alertaCodigoDocumentoVenda", "codigoDocumentoVenda", "Codigo", "campoCodigoDocumentoVenda", "text", "11",$select[0][0]);
//        Estrutura::criarInput("alertaTotalDocumentoVenda", "totalDocumentoVenda", "Total", "campoTotalDocumentoVenda", "text", "50",$select[0][1]);
//        Estrutura::criarInput("alertaSituacaoDocumentoVenda", "situacaoDocumentoVenda", "Situacao", "campoSituacaoDocumentoVenda", "text", "50",$select[0][2],true,true);
    }  
}

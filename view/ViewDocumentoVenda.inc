<?php

require_once './model/ModelEstrutura.inc';

/**
 * View de Documento Venda
 * @package view
 * @author Willeson Thomas da Silva <will.thomassilva@gmail.com>
 */
class ViewDocumentoVenda {

    /**
     * Cria a Formulário de cadastro do Documento Venda
     * @param int $iCodigoProduto
     */
    public function criarPaginaDocumentoVendaCadastrar($iCodigoProduto) {
        ModelEstrutura::criarFormulario("paginaPrincipalUsuario.php?pg=ViewDocumentoVenda", "Cadastro de Venda");
        ModelEstrutura::criarInput("alertaCodigoDocumentoVenda", "codigoDocumentoVenda", "Codigo da Venda", "campoCodigoDocumentoVenda", "text", "11", $iCodigoProduto, false, false, true);
        ModelEstrutura::criarInput("alertaCodigoProdutoDocumentoVenda", "codigoProdutoDocumentoVenda", "Codigo", "campoCodigoProdutoDocumentoVenda", "text", "11");
        ModelEstrutura::criarBotao("button", "BUSCAR PRODUTO", "buscarProduto");
        echo '<br>';
        ModelEstrutura::montaTabelaJs();
        echo '<br><br><br><br>';
        ModelEstrutura::criarBotao("submit", "CONFIRMAR", "cadastrarPessoaImovel");
        ModelEstrutura::criarBotao("reset", "CANCELAR", "limparImovel", true);
    }

    /**
     * Cria a tabela de Documento Venda
     * @param Array $select
     * @param Array $totalDocumentoVenda
     */
    public function criarPaginaDocumentoVendaExibir($select, $totalDocumentoVenda) {
        echo '<center><h1>Vendas Confirmadas</h1></center>';
        echo '<div style="height:700px">';
        ModelEstrutura::montarTabela(['Codigo da Venda', 'Total'], $select, true, true);
        echo '<center><h2>Total das Vendas: ' . $totalDocumentoVenda[0][0] . '<h2></center>';
        echo '</div>';
        echo '<br><hr><br>';
    }

}
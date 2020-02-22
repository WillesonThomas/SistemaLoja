<!DOCTYPE html>
<html>
    <head>
        <title>Pagina Inicial Usuario</title>
        <meta charset="windows-1252">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script src="http://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
        <link href="css/estiloPaginasCadastros.css" rel="stylesheet" type="text/css"/>
        <script src="scripts/scriptGenerico.js" type="text/javascript"></script>
        <script src="https://code.jquery.com/jquery-3.2.1.min.js" integrity="sha256-hwg4gsxgFZhOsEEamdOYGBf13FyQuiTwlAQgxVSNgt4=" crossorigin="anonymous"></script>
    </head>
    <body>
        <!------------------------------------------Menu------------------------------------------>
        <?php
        session_start();
        require_once './model/Estrutura.inc'; //encerra se não achar
        Estrutura::criarMenu();
        if (!isset($_GET['pg']) || ($_GET['pg']) == 'paginaPrincipalUsuario') {
            Estrutura::criarPaginaPrincipal();
            require_once './controller/ControllerPaginaPrincipal.inc'; //encerra se não achar
          $get = './controller/ControllerPaginaPrincipal';
        $oPaginaPrincipal = new ControllerPaginaPrincipal();
        }
        $get = '';
        if (isset($_GET['pg'])) {
            switch (($_GET['pg'])) {
                case "ViewPessoa":
                    require_once './controller/ControllerPessoa.inc'; //encerra se não achar
                    $get = './controller/ControllerPessoa';
                    $oPessoa = new ControllerPessoa();
                    break;
                case "ViewProduto":
                    require_once './controller/ControllerProduto.inc'; //encerra se não achar
                    $get = './controller/ControllerProduto';
                    $oProduto = new ControllerProduto();
                    break;
                case "ViewPedido":
                    require_once './controller/ControllerPedido.inc'; //encerra se não achar
                    $get = './controller/ControllerPedido';
                    $oPedido = new ControllerPedido();
                    break;
                default:
                    break;
            }
            Estrutura::carregarPagina($get);
        }
        ?>
        <footer>
            <h4>Sistema de Loja</h4>
            <p>Sistema desenvolvido para Senior Sistemas</p>
            <p>Desenvolvido por Willeson Thomas da Silva</p>
            <p>Contato: will.thomassilva@gmail.com</p><br>
        </footer>
    </body>
</html>
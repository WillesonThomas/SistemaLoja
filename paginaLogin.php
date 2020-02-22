<!DOCTYPE html>
<html>
    <head>
        <title>Pagina Inicial</title>
        <meta charset="windows-1252">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script src="http://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
        <link href="css/estiloPaginasCadastros.css" rel="stylesheet" type="text/css"/>
        <script src="scripts/scriptGenerico.js" type="text/javascript"></script>
    </head>
    <body>
        <!------------------------------------------FormulÃ¡rio------------------------------------------>
        <div id="formulario">
            <div class="container">
                <form method="POST" action="paginaLogin.php">
                    <center><h1>Login</h1></center>
                    <hr>
                    <div class="imgcontainer">
                        <img src="imagens/icones/person-icon.png" alt="Avatar" class="avatar">
                    </div>
                    <img src="imagens/icones/error.png" id="alertaUsuario" class="imagemalertasmall"/>
                    <label for="usuario"><b>Usuario*</b></label>
                    <input id="campoUsuario" type="text" name="usuario" required>

                    <img src="imagens/icones/error.png" id="alertaSenha" class="imagemalertasmall"/>
                    <label for="senha"><b>Senha*</b></label>
                    <input id="campoSenha" type="password" name="senha" required>

                    <hr>
                    <input type="submit" class="btnCadastrar" value="ENTRAR" id="entrarPagina">
                </form> 

                <?php
                //Realiza verificação de POST a respectiva chamada de função 'validarLogin'.
                session_start();
                if (!isset($_SESSION['usuarioSecao'])) {
                    if (isset($_POST['usuario']) and ! empty($_POST['usuario']) and isset($_POST['senha']) and ! empty($_POST['senha'])) {
                        require_once './model/Usuario.inc';
                        Usuario::validarLogin();
                    }
                } else {
                    session_destroy();
                }
                require_once './model/Estrutura.inc';
                Estrutura::criarAviso();
                ?>
            </div>
        </div>
        <footer style="margin-top: 38px; padding: 50px">
            <h4>Sistema de Loja</h4>
            <p>Desenvolvido por Willeson Thomas da Silva</p>
        </footer>
    </body>
</html>

                   /* // // // // //   //          //
                          //          //          //
                         //          //          //
                        //          // // // // //
                       //          //          //
                      //          //          //
                     //          //          //     */
                  
                  
                  /* Configurações de Update/Atualizaçoes Versão 2! */
                  
               /* CONFIGURAÇOES Updates/Atualizçoes_V2 code ! !*/

                  //   CRÉDITOS: © 2023 Thiago Macedo.   \\







#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>


ESP8266WebServer server(80);
ESP8266HTTPUpdateServer httpUpdater;


// # COISAS IMPORTANTES ANTES DE MODIFICAR FUTURAMENTE:
// # charset=utf-8 SERVER PARA OS TEXTOS NAO FICAREM BUGADOS.
// # USE SEMPRE O PADRÃO ** <meta charset="UTF-8" name="viewport" content="width=device-width, initial-scale=1"> ** POR QUE ELE DEIXA FUNCIONAL PARA CELULAR E LETRAS NORMAIS.
// © 2023 Thiago Macedo





// Página HTML de Login
const char* html = R"(
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" name="viewport" content="width=device-width, initial-scale=1">

<title>Painel de Atualização OTA</title>

<style>
html, body 
{
background-color: #f2f2f2;
font-family: Arial, sans-serif;
overflow: hidden;
}
.container {
max-width: 400px;
margin: 0 auto;
padding: 20px;
background-color: #fff;
border-radius: 5px;
box-shadow: 0 2px 5px rgba(0,0,0,0.1);
}
h1 {
text-align: center;
}
.form-group {
margin-bottom: 15px;
}
.form-group label {
display: block;
margin-bottom: 5px;
font-weight: bold;
}
.form-group input {
width: 96%;
padding: 10px;
font-size: 16px;
border-radius: 5px;
border: 1px solid #ccc;
}
.btn-container {
text-align: center;
}
.btn-container button {
transform: translate(-4px, 21px);
padding: 10px 20px;
font-size: 16px;
color: #fff;
background-color: #007bff;
border: none;
border-radius: 5px;
cursor: pointer;
}
.error-message {
color: red;
text-align: center;
margin-top: 33px;
}
.hh {
transform: translate(-12px, 29px);
text-align: center;
}
.ss {
transform: translate(25%, -247%);
text-align: center;
}
.ch {
transform: translate(48%, -248%) scale(1.5);
text-align: center;
-webkit-transform-origin-y: top;
}

@media screen and (max-width: 600px) {
/* Estilos para telas pequenas (por exemplo, dispositivos móveis) */
.container {
max-width: 100%;
height: 54%;
margin: 0;
border-radius: 10px;
/* Remover borda arredondada */
}
.form-group input {
width: 96%;
/* Largura total da tela */
}

.btn-container button {
transform: translate(-6px, 22px);
/* Remover transformações de posicionamento */
}

.ss {
transform: translate(24%, -262%);
text-align: center;
}

.ch {
transform: translate(50%, -215%) scale(1.5);
text-align: center;
-webkit-transform-origin-y: top;
}
}
</style>
</head>
<body>


<form action="/login" method="post">

    <div class="container" id="login-page">
    <h1>Painel de Atualização Manual OTA</h1>
    <div class="form-group">
    <label for="username">Usuário:</label>
    <input name="username" type="text" id="username" placeholder="Digite o usuário">
    </div>
   
    <div class="form-group">
    <label for="password">Senha:</label>
    <input id="password" name="password" type="password" placeholder="Digite a senha" maxlength="38">
    <input class="ch" type="checkbox" id="show-password">
    <label class="ss" for="show-password">Mostrar senha</label>
    </div>

    <div class="btn-container">
    <button type="submit" id="login-btn">Confirmar</button>
    </div>

    <div class="error-message" id="error-message"></div>
    <h4 class="hh">© 2023 Thiago Macedo</h4>
    </div>

    <div class="container" id="ota-panel" style="display: none;">
    <h1>Painel de Atualização OTA V1</h1>


    <h4 class="hh">© 2023 Thiago Macedo</h4>
    </div>

</form>


<script>
document.addEventListener('DOMContentLoaded', function() {
  var showPasswordCheckbox = document.getElementById('show-password');
  var passwordInput = document.getElementById('password');
  var loginBtn = document.getElementById('login-btn');

  passwordInput.addEventListener('keydown', function(event) {
    if (event.key === 'Enter') {
      event.preventDefault(); // Evitar o comportamento padrão do formulário ao pressionar Enter
      loginBtn.click(); // Disparar o evento de clique do botão Confirmar
    }
  });

  showPasswordCheckbox.addEventListener('change', function() {
    if (showPasswordCheckbox.checked) {
      passwordInput.type = 'text'; // Mostrar a senha
    } else {
      passwordInput.type = 'password'; // Esconder a senha
    }
  });

});
</script>

</body>
</html>
)";
// Página HTML de Login [FIM].








// Página HTML de Atualizar Código.
const char* OTAV1 = R"(
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8" name="viewport" content="width=device-width, initial-scale=1">

<title>Painel de Atualização OTA</title>

<style>
body {
background-color: #f2f2f2;
font-family: Arial, sans-serif;
}
.container {
max-width: 400px;
margin: 0 auto;
padding: 20px;
background-color: #fff;
border-radius: 5px;
box-shadow: 0 2px 5px rgba(0,0,0,0.1);
}
h1 {
text-align: center;
}
.form-group {
margin-bottom: 15px;
}
.form-group label {
display: block;
margin-bottom: 5px;
font-weight: bold;
}
.form-group input {
width: 96%;
padding: 10px;
font-size: 16px;
border-radius: 5px;
border: 1px solid #ccc;
}
.btn-container {
text-align: center;
}
.btn-container button {
transform: translate(-4px, 21px);
padding: 10px 20px;
font-size: 16px;
color: #fff;
background-color: #007bff;
border: none;
border-radius: 5px;
cursor: pointer;
}
.hh {
transform: translate(-12px, 29px);
text-align: center;
}

@media screen and (max-width: 600px) {
/* Estilos para telas pequenas (por exemplo, dispositivos móveis) */
.container {
max-width: 100%; /* Largura total da tela */
height: 54%;
margin: 0;
border-radius: 10px; /* Remover borda arredondada */
}
.form-group input {
width: 96%; /* Largura total da tela */
}
.btn-container button {
transform: translate(-6px, 22px); /* Remover transformações de posicionamento */
}
}
</style>
</head>
<body>
<div class="container" id="login-page">
<h1>Painel de Atualização Manual OTA V1</h1>

<div class="btn-container">
<form method='POST' action='/update' enctype='multipart/form-data'>
FIRMWARE:<br>
<input id="firmware-btn" type='file' accept='.bin,.bin.gz' name='firmware'>
<button id="codigo-btn" type='submit' >Atualizar Código</button>
</form>
</div>

<h4 class="hh">© 2023 Thiago Macedo</h4>
</div>

</body>
</html>

)";
// Página HTML de Atualizar Código[FIM]







void handleRoot_upd() 
{
  server.send(200, "text/html", html);
}



// Void PADRÃO Para LOGIN!
void handleLogin() {
  String username = server.arg("username");
  String password = server.arg("password");

  // Substitua com suas credenciais de usuário e senha desejadas
  if (username == "Admin" && password == "password") 
  {
     // Configurar HTTP Server e HTTP Update Server
    httpUpdater.setup(&server);
    delay(100);
    server.send(200, "text/html", OTAV1);
    // Lógica para redirecionar ou fazer outras ações aqui
  } 
  else 
  {
    // Exibir a mensagem de erro na mesma página de login
    String errorHtml = html;
    errorHtml.replace("<div class=\"error-message\" id=\"error-message\"></div>",  "<div class=\"error-message\" id=\"error-message\">Usuário ou senha incorretos.</div>");
    server.send(200, "text/html", errorHtml);
  }

}




// Void PADRÃO Para caso entre em uma rota não EXISTENTE!
void handleNotFound() {
  String message = "ERROR 404: Página não encontrada.";
  server.send(404, "text/plain; charset=utf-8", message);
}

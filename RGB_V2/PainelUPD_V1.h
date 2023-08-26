                   /* // // // // //   //          //
                          //          //          //
                         //          //          //
                        //          // // // // //
                       //          //          //
                      //          //          //
                     //          //          //     */
                  
                  
                  /* Configurações do Painel_UPDATES Versão 1! */
                  
               /* CONFIGURAÇOES Painel Atualizaçoes_V1 code ! !*/

                  //   CRÉDITOS: © 2023 Thiago Macedo.   \\






// # # # # #  CUIDADO AO USAR A FUNÇÃO <a> DE REDIRECIONAMENTO "<a href=""></a>" PODE SER QUE NO FUTURO JÁ TENHA RESOLVIDO MAIS AO USAR HTTPS POR ALGUM MOTIVO DA ERRO TENTE REDIRECIONAR PELO SERVIDOR OU POR JAVASCRIPT POIS ELE DA CONFLITO NESTE CÓDIGO!! # # # # # \\

bool ledState = LOW; // LED já inicia desligado.
bool d5State = HIGH; // Estado inicial da porta D5.
bool d6State = HIGH; // Estado inicial da porta D6.


String ledButtonState = "Ligar Refrigeramento TURBO";
String d5ButtonState = "Ligar Led Frontal";
String d6ButtonState = "Ligar Led Interna";
String allButtonState = "Carregando...";

// Defina a página HTML como um const char
const char PROGMEM html_PUDP[] = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8" name="viewport" content="width=device-width, initial-scale=1">
    <title>Controle de LED</title>

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
            font-size: 28px;
        }
        
        h1 .rgb-effect {
            animation: rgbEffect 15s infinite;
            color: #007bff;
        }
        
        @keyframes rgbEffect {
          0% {
            color: #008cff;
        }
        10% {
            color: #00ff00; /* Verde Claro */
        }
        15% {
            color: #00ff00; /* Verde Claro */
        }
        20% {
            color: #ff0000; /* Vermelho */
        }
        22% {
            color: #ff00ff; /* Rosa */
        }
        25% {
            color: #ff09ff; /* Roxo */
        }
        30% {
            color: #827300cc; /* Indigo */
        }
        32% {
            color: #ffd700; /* Amarelo */
        }
        40% {
            color: #ffd700; /* Amarelo */
        }
        42% {
            color: #ff4500; /* Laranja Vermelho */
        }
        45% {
            color: #ff1493; /* Rosa Choque */
        }
        50% {
            color: #8a2be2; /* Azul Violeta */
        }
        55% {
            color: #0000ff; /* Azul */
        }
        60% {
            color: #00bfff; /* Azul Claro */
        }
        75% {
            color: #00ff9d; /* Azul */
        }
        80% {
            color: #ffd700; /* Amarelo */
        }
        85% {
            color: #ffa600; /* Amarelo */
        }
        90% {
            color: #007bff; /* Azul */
        }
        95% {
            color: #ff0077; /* Azul */
        }
        100% {
            color: #00ddff;
        }
        
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
            width: 70%; /* Largura fixa para todos os botões */
            padding: 14px 15px;
            font-size: 18px;
            color: #fff;
            background-color: #007bff;
            border: none;
            border-radius: 15px;
            cursor: pointer;
            margin: 5px 0; /* Espaçamento entre os botões (vertical) */
            transition: background-color 0.3s ease, transform 0.2s ease; /* Transições suaves */
        }
        
        .btn-container button:active {
            background-color: navy; /* Cor ao clicar */
        }
        
        .btn-container button:hover {
            background-color: #09def3; /* Cor ao passar o mouse */
            transform: scale(1.05); /* Efeito de escala ao passar o mouse */
        }
        
        .error-message {
            color: red;
            text-align: center;
            margin-top: 33px;
        }
        
        .hh {
            text-align: center;
        }
        
        @media screen and (max-width: 600px) {
            /* Estilos para telas pequenas (por exemplo, dispositivos móveis) */
            .container {
                max-width: 100%;
                height: 55%;
                margin: 0;
                border-radius: 10px;
                /* Remover borda arredondada */
            }
        
            .form-group input {
                width: 96%;
                /* Largura total da tela */
            }
        
            .btn-container button {
                /* Remover transformações de posicionamento */
            }
        
        }
    </style>
    
</head>

<body>

       <div class="container" id="login-page">
           <h1><span id="instagram-link" class="rgb-effect" style="text-decoration: none; cursor: pointer;">RGB</span><span style="text-decoration: none;">-PC</span>_V1</h1>
      
          <div class="btn-container">
              <button  id="ledButton">Carregando...</button>
          
              <button id="d5Button">Carregando...</button>
          
              <button id="d6Button">Carregando...</button>
          
              <button id="allButton">Carregando...</button>
        
              <button onclick="window.location.href='/Atualizar'">Atualizar !</button>
          </div>
      
           <h4 id="instagram-footer" class="hh" style="color: black; text-decoration: none; cursor: pointer;">© 2023 Thiago Macedo</h4>
      </div>

      
      
    
    <script>
        const ledButton = document.getElementById('ledButton');
        const d5Button = document.getElementById('d5Button');
        const d6Button = document.getElementById('d6Button');
        const allButton = document.getElementById('allButton');
      



        // Elemento "RGB" no cabeçalho
        const rgbLink = document.getElementById('instagram-link');
        rgbLink.addEventListener('click', function () 
        {
            window.location.href = 'https://www.instagram.com/thiago4macedo/?theme=dark';
        });



    
        // Rodapé "© 2023 Thiago Macedo"
        const instagramFooter = document.getElementById('instagram-footer');
        instagramFooter.addEventListener('click', function () 
        {
            window.location.href = 'https://www.instagram.com/thiago4macedo/?theme=dark';
        }); 



        // Função para redirecionar um click sobre o botão para "Verificação de Condição ON ou OFF".
       
        ledButton.addEventListener('click', function() 
        {
            toggle('/toggle', ledButton);
        });

        
        d5Button.addEventListener('click', function() 
        {
            toggle('/toggleD5', d5Button);
        });
        
        d6Button.addEventListener('click', function() 
        {
            toggle('/toggleD6', d6Button);
        });
        
        allButton.addEventListener('click', function() 
        {
            toggleAll();
        });
       // Função para redirecionar um click sobre o botão para "Verificação de Condição ON ou OFF". [FIM]



      // FUNÇOES PARA VERIFICAR 1 CLICK DE CADA.
      function toggle(url, button) 
      {

        let l = ''; // Variável para "Ligar"
        let d = ''; // Variável para "Desligar"
        let newStatus = '';
        
        if (button.innerText == 'Ligar Refrigeramento TURBO' || button.innerText == 'Desligar Refrigeramento TURBO') 
        {
            newStatus = (button.innerText === 'Ligar Refrigeramento TURBO') ? 'on' : 'off';
            l = 'Ligar Refrigeramento TURBO';
            d = 'Desligar Refrigeramento TURBO';
        } 
        else if (button.innerText == "Ligar Led Frontal" || button.innerText == "Desligar Led Frontal") {
            newStatus = (button.innerText === 'Ligar Led Frontal') ? 'on' : 'off';
            l = 'Ligar Led Frontal';
            d = 'Desligar Led Frontal';
        }
        else if (button.innerText == "Ligar Led Interna" || button.innerText == "Desligar Led Interna") 
        {
            newStatus = (button.innerText === 'Ligar Led Interna') ? 'on' : 'off';
            l = 'Ligar Led Interna';
            d = 'Desligar Led Interna';
       }


        

          
          fetch(url, 
          {
              method: 'POST',
              body: newStatus,
          }).then(() => {
              button.innerText = (newStatus === 'on') ? d : l;
          });
      }








        function toggleAll() 
        {
            const newStatus = (allButton.innerText === 'Ligar Tudo') ? 'on' : 'off';
            fetch('/toggleAll', 
            {
                method: 'POST',
                body: newStatus,
            }).then(() => {
                ledButton.innerText = (newStatus === 'on') ? 'Desligar Refrigeramento TURBO' : 'Ligar Refrigeramento TURBO';
                d5Button.innerText = (newStatus === 'on') ? 'Desligar Led Frontal' : 'Ligar Led Frontal';
                d6Button.innerText = (newStatus === 'on') ? 'Desligar Led Interna' : 'Ligar Led Interna';
                allButton.innerText = (newStatus === 'on') ? 'Desligar Tudo' : 'Ligar Tudo';
            });
        }






        function checkLEDState() 
        {
            fetch('/ledstate').then(response => response.text()).then(data => 
            {
                ledButton.innerText = (data === 'on') ? 'Desligar Refrigeramento TURBO' : 'Ligar Refrigeramento TURBO';
            });
            
            
            fetch('/d5state').then(response => response.text()).then(data => {
                d5Button.innerText = (data === 'on') ? 'Desligar Led Frontal' : 'Ligar Led Frontal';
            });
            
            fetch('/d6state').then(response => response.text()).then(data => {
                d6Button.innerText = (data === 'on') ? 'Desligar Led Interna' : 'Ligar Led Interna';
            });

            // Atualize o estado do botão "Ligar/Desligar Tudo" com base nos estados dos outros botões.
            if (ledButton.innerText === 'Ligar Refrigeramento TURBO' && d5Button.innerText === 'Ligar Led Frontal' && d6Button.innerText === 'Ligar Led Interna') {
                allButton.innerText = 'Ligar Tudo';
            } else {
                allButton.innerText = 'Desligar Tudo';
            }
            
            setTimeout(checkLEDState, 1000); // Verifique o estado a cada 1 segundo
        }
        
        checkLEDState(); // Inicie a verificação do estado ao carregar a página
    </script>
</body>
</html>
)=====";






// Declaraçoes das funçãoes toggleHandler e handleToggleS.
void toggleHandler(const String &url, String &buttonState, bool &state) 
{
    if (server.method() == HTTP_POST) 
    {
        String newStatus = server.arg("plain");
        
        if (newStatus == "on") 
        {
            state = HIGH;
        } 
        else if (newStatus == "off") 
        {
            state = LOW;
        }

        digitalWrite(LED_BUILTIN, ledState);
       
        buttonState = (state == HIGH) ? "Desligar" : "Ligar";
        
        server.send(200, "text/plain", newStatus);
    }
}


void handleRoot() 
{
    server.send(200, "text/html", html_PUDP);
}


void handleToggle() 
{
    toggleHandler("/toggle", ledButtonState, ledState);
}


void handleToggleD5() 
{
    toggleHandler("/toggleD5", d5ButtonState, d5State);
}


void handleToggleD6() 
{
    toggleHandler("/toggleD6", d6ButtonState, d6State);
}


void handleToggleAll() 
{
    if (server.method() == HTTP_POST) 
    {
        String newStatus = server.arg("plain");
        
        if (newStatus == "on") 
        {
            ledState = HIGH;
            d5State = HIGH;
            d6State = HIGH;
        } 
        else if (newStatus == "off") 
        {
            ledState = LOW;
            d5State = LOW;
            d6State = LOW;
        }

        digitalWrite(LED_BUILTIN, ledState);
    
        ledButtonState = (ledState == HIGH) ? "Desligar Refrigeramento TURBO" : "Ligar Refrigeramento TURBO";
        d5ButtonState = (d5State == HIGH) ? "Desligar Led Frontal" : "Ligar Led Frontal";
        d6ButtonState = (d6State == HIGH) ? "Desligar Led Interna" : "Ligar Led Interna";
        allButtonState = (newStatus == "on") ? "Desligar Tudo" : "Ligar Tudo";
        
        server.send(200, "text/plain", newStatus);
    }
}


void handleLEDState() 
{
    server.send(200, "text/plain", ledState ? "on" : "off");
}


void handleD5State() 
{
    server.send(200, "text/plain", d5State ? "on" : "off");
}


void handleD6State() 
{
    server.send(200, "text/plain", d6State ? "on" : "off");
}






/*
// Void PADRÃO Para caso entre em uma rota não EXISTENTE ou LINKs HTTPS!
void handleNotFoundUPD() 
{
  String message = "ERROR 404: Página não encontrada.";
  server.send(404, "text/plain; charset=utf-8", message);
}
*/



void handles_PUPD()
{
  
  // Configura os handlers de rota
  server.on("/toggle", HTTP_POST, handleToggle);
  server.on("/toggleD5", HTTP_POST, handleToggleD5);
  server.on("/toggleD6", HTTP_POST, handleToggleD6);
  server.on("/toggleAll", HTTP_POST, handleToggleAll);
  server.on("/ledstate", HTTP_GET, handleLEDState);
  server.on("/d5state", HTTP_GET, handleD5State);
  server.on("/d6state", HTTP_GET, handleD6State);
}

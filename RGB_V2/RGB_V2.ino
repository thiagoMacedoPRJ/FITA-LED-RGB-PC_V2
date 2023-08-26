#include <ESP8266WiFi.h>
#include "Updates_V2.h"
#include "PainelUPD_V1.h"
#include "Func_LEDs_V1.h"


// Defina o nome e a senha do ponto de acesso
const char* apSSID = "RGB-PC";
const char* apPassword = "corsair450";



// Alterar endereço padrão do gateway para 45. por causa da fonte 450. EGG ! !
IPAddress local_IP(192,168,4,45);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);





void setup() 
{
  Serial.begin(115200);  // Inicializa a comunicação serial

  
  // Configura a rede do ESP8266
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(apSSID, apPassword);  // Configura o ESP8266 como um ponto de acesso


  // Configuração Setup Leds.
  leds_normais_setup();
  leds_ARGB_setup();
  Turbo_setup();


  // Configura rotas da web
  server.on("/", HTTP_GET, handleRoot);
  server.on("/Atualizar", HTTP_GET, handleRoot_upd);
  server.on("/login", HTTP_POST, handleLogin);


  // Conf Handles/Rotas PainelUPD
  handles_PUPD();


  // Inicia o servidor web
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Servidor web iniciado");


  // Obtenha o endereço IP do ponto de acesso
  Serial.print("Endereço IP do AP: ");
  Serial.println(WiFi.softAPIP());
}




//=======================================================================
//                    LOOP
//=======================================================================



void loop() 
{
 server.handleClient(); // Mantem os servers Ligados.
 leds_normais();
 leds_ARGB();
 Turbo();
}

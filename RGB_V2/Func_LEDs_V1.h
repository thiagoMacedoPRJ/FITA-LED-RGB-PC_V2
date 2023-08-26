                   /* // // // // //   //          //
                          //          //          //
                         //          //          //
                        //          // // // // //
                       //          //          //
                      //          //          //
                     //          //          //     */
                  
                  
                  /* Configurações de Funçoes/LEDs Versão 1! */
                  
               /* CONFIGURAÇOES Funçoes é LEDs_V1 code ! !*/

                  //   CRÉDITOS: © 2023 Thiago Macedo.   \\

#include <FastLED.h>




// LEDs ENDEREÇAVEIS CONFIGURAÇOES [FIM]

#define DATA_PIN    D5       // pino da ESP8266 conectado à fita de LEDs WS2812B
#define LED_TYPE    WS2812B  // tipo de LED
#define COLOR_ORDER GRB      // ordem das cores na fita de LED WS2812B
#define NUM_LEDS    30       // número de LEDs na fita

CRGB leds[NUM_LEDS];        // array para armazenar as cores dos LEDs

#define BRIGHTNESS          96   // brilho dos LEDs (de 0 a 255)
#define FRAMES_PER_SECOND  120   // taxa de atualização dos LEDs (frames por segundo)







uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns
   




// LEDs ENDEREÇAVEIS CONFIGURAÇOES [FIM]










// Funçoes TURBO/Relé [INICIO]

int p_Turbo = 2; //PINO DIGITAL UTILIZADO PELO MÓDULO RELÉ

void Turbo_setup()
{
  pinMode(p_Turbo, OUTPUT); //DEFINE O PINO COMO SAÍDA
 
  digitalWrite(p_Turbo, HIGH); //MÓDULO RELÉ INICIA DESLIGADO
}


void Turbo()
{
  if (ledState == LOW)
  {
      digitalWrite(p_Turbo, HIGH); //MÓDULO RELÉ INICIA DESLIGADO
  }
  else
  {
      digitalWrite(p_Turbo, LOW); //MÓDULO RELÉ LIGADO
  }
  
}

// Funçoes TURBO/Relé [FIM]










//variáveis de controle para cada cor do padrão RGB LEDS NORMAIS
int vermelho, verde, azul;




//LED Connections
#define R D6
#define G D7
#define B D8


int current[3] = {0, 0, 0};  // [R, G, B]
int target[3] = {0, 0, 0};   // [R, G, B]

unsigned long lastUpdate = 0;
unsigned long transitionDuration = 2000; // Duração da transição em milissegundos


// é usado para representar os diferentes estados a LED pode atingir.
enum ColorState {
  GREEN,
  GREEN_F,
  LIGHT_GREEN,
  ORANG,
  BLUE,
  ORANG_BB,
  NAVY_BLUE,
  CYAN,
  ORANG_C,
  RED,
  YELLO,
  YELLO_B,
  PINK,
  PURPLE,
  PINK_B,
  PURPLE_TO_GREEN,
  INCREMENT_RED,
  REMOVE_BLUE,
  INCREMENT_GREEN,
  REMOVE_RED,
  ADD_BLUE_RED,
  REMOVE_GREEN,
  CYAN_B
};

ColorState currentState = LIGHT_GREEN;

void updateColor(int pin, int index, int targetValue) {
  if (current[index] != targetValue) {
    if (current[index] < targetValue) {
      current[index]++;
    } else {
      current[index]--;
    }
    analogWrite(pin, current[index]);
  }
}

void leds_normais_setup() 
{
  // Configurar os pinos PWM do Arduino como saída
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}



void leds_normais() 
{
  unsigned long currentTime = millis();

  if (d6State == HIGH)
  {
            if (currentTime - lastUpdate >= transitionDuration) {
              lastUpdate = currentTime;
              
              switch (currentState) {
                case GREEN:
                  target[0] = 0;
                  target[1] = 255;
                  target[2] = 0;
                  currentState = GREEN_F;
                  break;
                case GREEN_F:
                  target[0] = 0;
                  target[1] = 250;
                  target[2] = 0;
                  currentState = LIGHT_GREEN;
                  break;
                case LIGHT_GREEN:
                  target[0] = 173;
                  target[1] = 255;
                  target[2] = 47;
                  currentState = ORANG;
                  break;
               case ORANG:
                  target[0] = 255;
                  target[1] = 128;
                  target[2] = 0;
                  currentState = BLUE;
                  break;
          
                case BLUE:
                  target[0] = 0;
                  target[1] = 128;
                  target[2] = 255;
                  currentState = ORANG_BB;
                  break;
          
                case ORANG_BB:
                  target[0] = 255;
                  target[1] = 168;
                  target[2] = 0;
                  currentState = NAVY_BLUE;
                  break;
                  
                case NAVY_BLUE:
                  target[0] = 0;
                  target[1] = 0;
                  target[2] = 128;
                  currentState = CYAN;
                  break;
                case CYAN:
                  target[0] = 0;
                  target[1] = 255;
                  target[2] = 255;
                  currentState = ORANG_C;
                  break;
                case ORANG_C:
                  target[0] = 255;
                  target[1] = 165;
                  target[2] = 0;
                  currentState = RED;
                  break;
                case RED:
                  target[0] = 255;
                  target[1] = 0;
                  target[2] = 0;
                  currentState = YELLO;
                  break;
          
                case YELLO:
                  target[0] = 255;
                  target[1] = 255;
                  target[2] = 0;
                  currentState = YELLO_B;
                  break;
          
                case YELLO_B:
                  target[0] = 255;
                  target[1] = 255;
                  target[2] = 128;
                  currentState = PINK;
                  break;
                  
                case PINK:
                  target[0] = 255;
                  target[1] = 105;
                  target[2] = 180;
                  currentState = PURPLE;
                  break;
          
          
          
                case INCREMENT_RED:
                  target[0] += 10;
                  if (target[0] >= 255) {
                    currentState = REMOVE_BLUE;
                    target[0] = 255;
                  }
                  break;
                 
               case PURPLE:
                  target[0] = 128;
                  target[1] = 0;
                  target[2] = 128;
                  currentState = PINK_B;
                  break;
          
          
          
                case PINK_B:
                  target[0] = 255;
                  target[1] = 105;
                  target[2] = 180;
                  currentState = PURPLE_TO_GREEN;
                  break;
                  
                case PURPLE_TO_GREEN:
                  target[0] = 100;
                  target[1] = 255;
                  target[2] = 100;
                  currentState = GREEN;
                  break;
               
                case REMOVE_BLUE:
                  target[2] = 0;
                  currentState = INCREMENT_GREEN;
                  break;
                case INCREMENT_GREEN:
                  target[1] += 10;
                  if (target[1] >= 255) {
                    currentState = REMOVE_RED;
                    target[1] = 255;
                  }
                  break;
                case REMOVE_RED:
                  target[0] = 0;
                  currentState = ADD_BLUE_RED;
                  break;
                case ADD_BLUE_RED:
                  target[0] = 255;
                  target[2] = 255;
                  currentState = REMOVE_GREEN;
                  break;
                case REMOVE_GREEN:
                  target[1] = 0;
                  currentState = CYAN_B;
                  break;
              }
            }
            
            updateColor(R, 0, target[0]);
            updateColor(G, 1, target[1]);
            updateColor(B, 2, target[2]);
    
  }
 else
 {
    target[0] = 0;

    target[1] = 0;
  
    target[2] = 0;
  
    updateColor(R, 0, target[0]);
    updateColor(G, 1, target[1]);
    updateColor(B, 2, target[2]);
  }

      
}


  



//variáveis de controle para cada cor do padrão RGB LEDS NORMAIS [FIM]







// EFEITOS LEDS ENDEREÇAVEIS
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))



void rainbow() {
  fill_rainbow(leds, NUM_LEDS, gHue, 7);
}


void addGlitter(fract8 chanceOfGlitter) {
  if (random8() < chanceOfGlitter) {
    leds[random16(NUM_LEDS)] += CRGB::White;
  }
}


void rainbowWithGlitter() {
  rainbow();
  addGlitter(80);
}


void confetti() {
  fadeToBlackBy(leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV(gHue + random8(64), 200, 255);
}

void sinelon() {
  fadeToBlackBy(leds, NUM_LEDS, 20);
  int pos = beatsin16(13, 0, NUM_LEDS - 1);
  leds[pos] += CHSV(gHue, 255, 192);
}

void bpm() {
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8(BeatsPerMinute, 64, 255);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
  }
}

void juggle() {
  fadeToBlackBy(leds, NUM_LEDS, 20);
  byte dothue = 0;
  for (int i = 0; i < 8; i++) {
    leds[beatsin16(i + 7, 0, NUM_LEDS - 1)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}


// Lista de padrões para percorrer. Cada um é definido como uma função separada abaixo.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm };

 
void nextPattern() 
{
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE(gPatterns);
}



void leds_ARGB_setup()
{
  // informa ao FastLED sobre a configuração da faixa de LED
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
 
  // define o controle mestre de brilho
  FastLED.setBrightness(BRIGHTNESS);
}






// Função para ligar os efeitos ARGB FRONTAL.
void leds_ARGB()
{
  if (d5State == HIGH)
  {
    // Chama a função padrão atual uma vez, atualizando o array 'leds'
    gPatterns[gCurrentPatternNumber]();
   
    // envia o array de 'leds' para a faixa de LED real
    FastLED.show();  
    //inserir um atraso para manter a taxa de quadros modesta
    FastLED.delay(2000/FRAMES_PER_SECOND); 
   
    //faz algumas atualizações periódicas
    EVERY_N_MILLISECONDS( 20 ) { gHue++; } // percorre lentamente a "cor base" através do arco-íris
    EVERY_N_SECONDS( 10 ) { nextPattern(); } //muda os padrões periodicamente
  }
  else
  {
    FastLED.clear(); // Apague todas as LEDs
  
    FastLED.show(); // Atualize os LEDs com as novas cores
  }
}

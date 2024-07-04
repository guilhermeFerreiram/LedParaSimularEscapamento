#include <Adafruit_NeoPixel.h>

#define LED_PIN    6
#define NUM_LEDS   99
#define FIRST_BREAKPOINT 11
#define SECOND_BREAKPOINT 26
#define THIRD_BREAKPOINT 70
#define FOURTH_BREAKPOINT 80

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

const uint32_t RED = strip.Color(255, 0, 0);
const uint32_t GREEN = strip.Color(0, 255, 0);
const uint32_t BLUE = strip.Color(0, 0, 255);

void setup() {
  strip.begin();
  strip.show(); // Inicializa todos os LEDs para estar apagados
}

void loop() {
  //Acende os LEDs em vermelho até o final do catalisador para simular ar nocivo
  AcenderLeds(0, SECOND_BREAKPOINT, RED, 50);

  //Alterna os LEDs do catalisador entre vermelho e azul para simular o processo de filtragem
  AcenderLeds(FIRST_BREAKPOINT, SECOND_BREAKPOINT, BLUE, 0);
  delay(500);
  AcenderLeds(FIRST_BREAKPOINT, SECOND_BREAKPOINT, RED, 0);
  delay(500);
  AcenderLeds(FIRST_BREAKPOINT, SECOND_BREAKPOINT, BLUE, 0);
  delay(500);
  AcenderLeds(FIRST_BREAKPOINT, SECOND_BREAKPOINT, RED, 0);
  delay(500);
  AcenderLeds(FIRST_BREAKPOINT, SECOND_BREAKPOINT, BLUE, 0);
  delay(500);

  //Acende os LEDs em azul até o final do difusor para simular ar filtrado
  AcenderLeds(SECOND_BREAKPOINT, FOURTH_BREAKPOINT, BLUE, 50);

  //Acende e apaga os LEDs do difusor para simular a circulação do ar dentro do escapamento
  ApagarLeds(FOURTH_BREAKPOINT, THIRD_BREAKPOINT, 50);
  AcenderLeds(THIRD_BREAKPOINT, FOURTH_BREAKPOINT, BLUE, 50);

  //Acende os LEDs em verde para simular a saída do ar para o meio-ambiente
  AcenderLeds(FOURTH_BREAKPOINT, NUM_LEDS, GREEN, 50);
  delay(2000);

  // Define a cor de todos os LEDs como preto para reiniciar o processo
  strip.fill(strip.Color(0, 0, 0));
  strip.show();

}

void AcenderLeds(int firstLED, int lastLED, uint32_t color, int time){
  for (int i = firstLED; i < lastLED; i++){
    strip.setPixelColor(i, color);
    strip.show();
    delay(time);
  }
}

void ApagarLeds(int firstLED, int lastLED, int time){
  for (int i = firstLED; i >= lastLED; i--){
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.show();
    delay(time);
  }
}

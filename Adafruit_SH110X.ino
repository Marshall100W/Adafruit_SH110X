//////////////////////////////////

#include <Adafruit_SH110X.h>
#include <Adafruit_GFX.h>

Adafruit_SH1106G oled = Adafruit_SH1106G(128, 64, &Wire, -1);

uint32_t tmp_contador = 0;
uint16_t contador = 0;

void setup() {
  Serial.begin(115200);
  inicio_oled();
  delay(3000);
  Serial.println("UP THE IRONS!");
}

void loop() {
  func_contador();
}


void inicio_oled() {
  oled.begin(0x3C, true);
  oled.clearDisplay();
  oled.drawRect(0, 0, 128, 16, 1);
  oled.drawRect(0, 17, 128, 47, 1);
  oled.setTextSize(1);
  oled.setTextColor(1, 0);
  oled.setCursor(25, 5);
  oled.print(F("UP THE IRONS!"));
  oled.display();
  oled.setTextSize(2);
}


void func_contador() {
  if (millis() - tmp_contador >= 1000) {
    tmp_contador = millis();
    char texto[6];
    sprintf(texto, "%5d", contador);
    oled.setCursor(25, 25);
    oled.print(texto);
    oled.display();
    contador++;
  }
}
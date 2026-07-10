#include <Keyboard.h>

void enter() {
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void setup() {
  // Elegí el layout de la PC DESTINO (descomentá uno solo):
  //Keyboard.begin(KeyboardLayout_es_ES);
  Keyboard.begin(KeyboardLayout_en_US);

  delay(2000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);

  Keyboard.print("notepad");
  enter();
  delay(800);

  Keyboard.print("hola te saludo, ¿cómo estás? buenos días ------(---);   ");

  Keyboard.end();
}

void loop() {}

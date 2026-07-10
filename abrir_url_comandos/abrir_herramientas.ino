#include <Keyboard.h>

// --- Ajustá esto si en tu PC target falla ---
const int DELAY_TECLA = 3;   // ms entre press/release de cada tecla del numpad
const int DELAY_ALT   = 3;   // ms extra antes de soltar Alt
// ---------------------------------------------

void altChar(int code) {
  Keyboard.press(KEY_LEFT_ALT);
  char buf[5];
  sprintf(buf, "%04d", code);
  for (int i = 0; i < 4; i++) {
    int d = buf[i] - '0';
    int key = (d == 0) ? KEY_KP_0 : (KEY_KP_1 + (d - 1));
    Keyboard.press(key);
    delay(DELAY_TECLA);
    Keyboard.release(key);
    delay(DELAY_TECLA);
  }
  delay(DELAY_ALT);
  Keyboard.release(KEY_LEFT_ALT);
}

// Función lista para reusar: escribe cualquier texto, cualquier teclado
void escribirUniversal(const char* texto) {
  for (int i = 0; texto[i] != '\0'; i++) {
    altChar((int)texto[i]);
  }
}

// Atajo para simplificar Enter, sin repetir press/release/releaseAll
void enter() {
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void setup() {
  Keyboard.begin();
  delay(2000);

  //abrir el ejecutar 
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);//esperar

  // las instrucciones empiezan aqui======================
  escribirUniversal("notepad");
  enter();  //abrir notepad
  delay(500);
  escribirUniversal("Fuiste hackeado jajajajj --hack-gris-- ");
 
  

  delay(1000);

  //============== termina aqui ===========================
  Keyboard.end();
}

void loop() {}

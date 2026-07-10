#include <Keyboard.h>

// --- Ajustá esto si en tu PC target falla ---
const int DELAY_TECLA = 3;   // ms entre press/release de cada tecla del numpad
const int DELAY_ALT   = 4;   // ms extra antes de soltar Alt
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
  delay(2); // respiro entre caracteres, ayuda en RDP/VM
}

// Decodifica UTF-8 (solo hasta 2 bytes, cubre á é í ó ú ñ ¿ ¡ ü y sus mayúsculas)
int nextCodepoint(const char* texto, int &i) {
  unsigned char c = texto[i];
  if (c < 0x80) {                       // ASCII normal
    i += 1;
    return c;
  } else if ((c & 0xE0) == 0xC0) {      // 2 bytes -> Latin-1 Supplement
    unsigned char c2 = texto[i+1];
    int cp = ((c & 0x1F) << 6) | (c2 & 0x3F);
    i += 2;
    return cp;                          // coincide con cp1252 para estos casos
  } else {
    i += 1;                             // byte raro, lo salteamos
    return -1;
  }
}


// Función lista para reusar: escribe cualquier texto, cualquier teclado
void escribirUniversal(const char* texto) {
  int i = 0;
  while (texto[i] != '\0') {
    int cp = nextCodepoint(texto, i);
    if (cp > 0) altChar(cp);
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
  escribirUniversal("cmd");//escribir
  enter();
  delay(1200);//esperar

  escribirUniversal("start https://youtu.be/cHHLHGNpCSA");
  enter();

  //============== termina aqui ===========================
  Keyboard.end();
}

void loop() {}

#include <Keyboard.h>

const int DELAY_TECLA = 3;
const int DELAY_ALT   = 4;

// ---------- Alt-code: universal, cualquier layout ----------
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
  delay(2);
}

// ---------- Decodifica UTF-8 a codepoint ----------
int nextCodepoint(const char* texto, int &i) {
  unsigned char c = texto[i];
  if (c < 0x80) {
    i += 1;
    return c;
  } else if ((c & 0xE0) == 0xC0) {
    unsigned char c2 = texto[i + 1];
    int cp = ((c & 0x1F) << 6) | (c2 & 0x3F);
    i += 2;
    return cp;
  }
  i += 1;
  return -1;
}

// ---------- Escribe cualquier texto, cualquier teclado ----------
void escribirUniversal(const char* texto) {
  int i = 0;
  while (texto[i] != '\0') {
    int cp = nextCodepoint(texto, i);
    if (cp < 0) continue;
    if (cp < 128) Keyboard.write((char)cp);
    else altChar(cp);
  }
}

void enter() {
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void setup() {
  Keyboard.begin();
  delay(2000);

  // Abrir "Ejecutar"
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);

  // ===== instrucciones =====
  escribirUniversal("notepad");
  enter();
  delay(800);

  escribirUniversal("hola te saludo, ¿cómo estás? buenos días ------(---);   ");
  // ==========================

  Keyboard.end();
}

void loop() {}

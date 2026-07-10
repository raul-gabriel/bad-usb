# BadUSB - Prank YouTube (Arduino/Digispark)

## Qué hace
Emula un teclado USB (HID) que abre `Ejecutar` (Win+R), abre `cmd` y lanza una URL de YouTube con `start`.

## Compatibilidad
- **SO:** Solo Windows (usa Alt+código numérico, exclusivo de Windows).
- **Teclado:** Cualquier layout (ES, EN, FR, DE, etc.) porque no depende de la posición física de las teclas.
- **Requisito:** NumLock debe estar activado en el equipo destino. No se puede verificar ni forzar de forma segura desde el Arduino (activar el NumLock a ciegas podría *apagarlo* si ya estaba encendido).

## Cómo funciona
Cada carácter se manda como `Alt + código numérico` usando el teclado numérico virtual, en vez de usar `Keyboard.print()`. Por eso el idioma del teclado configurado en el sistema no afecta el resultado.

## Uso
Llamar a `escribirUniversal("texto")` para tipear cualquier cadena ASCII imprimible, y combinarlo con teclas especiales (`KEY_RETURN`, `KEY_LEFT_GUI`, etc.) igual que con `Keyboard.press()`.

## Limitaciones
- No soporta tildes, `ñ`, ni caracteres fuera de ASCII básico.
- No funciona en macOS/Linux.
- Es más lento que tipear directo (4 teclas por carácter), mitigado con delays ajustados al mínimo estable.

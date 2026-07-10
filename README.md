# BadUSB Educativo con Arduino

Proyecto educativo para demostrar cómo un dispositivo USB puede emular un teclado y ejecutar comandos automáticamente (estilo USB Rubber Ducky).  
**Creado con fines educativos para feria universitaria.**

---

## 🎯 Objetivo

Al conectar el Arduino, este actúa como un teclado USB y ejecuta comandos de forma automática: abre URLs, videos de YouTube, herramientas de Windows, etc.

---

## Ventajas de usar ATMega32U4

Elegimos la placa **ATMega32U4** (Arduino Leonardo / Micro) porque ofrece:

- **Mayor estabilidad y confiabilidad** (menos fallos al ser reconocido por Windows)
- Más memoria disponible para payloads complejos
- Más fácil de programar (no requiere drivers especiales)
- Mejor rendimiento en demostraciones en vivo (ideal para ferias)
- Más profesional y robusto comparado con placas más baratas como el Digispark ATtiny85

Aunque el Digispark es más pequeño y barato, el **ATMega32U4** es la mejor opción para proyectos educativos y demostraciones.

---

## Placas Compatibles

Este código funciona correctamente con placas que tengan **ATMega32U4**:

- **Arduino Leonardo**
- **Arduino Micro**
- **SparkFun Pro Micro** (ATMega32U4)
- **Arduino Leonardo ETH**
- Cualquier clon chino con ATMega32U4

**No funciona** con Arduino Uno, Nano, Mega (no soportan USB HID nativo).

---

## Requisitos

- Arduino IDE (versión 2.x recomendada)
- Placa con **ATMega32U4**
- Cable USB de datos
- Computadora objetivo con **Windows** (probado en Windows 10 y 11)
- Conocimientos básicos de Arduino

---

## Cómo Usarlo

1. Abre el archivo `.ino` en Arduino IDE.
2. Selecciona tu placa (**Arduino Leonardo** o **Micro**).
3. Cambia el enlace o comando según necesites.
4. Sube el código.
5. Prueba conectando el dispositivo en una PC Windows.

---

## Advertencia Educativa

Este proyecto es **solo con fines educativos y de demostración**.  
No utilizar para actividades maliciosas. El objetivo es aprender sobre seguridad informática y ataques de tipo BadUSB / Rubber Ducky.

---

**¡Úsalo responsablemente y diviértete enseñando!** 🚀

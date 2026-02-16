# Led2

Proyecto de control de tira LED WS2812B utilizando NodeMCU (ESP8266) con efectos de color dinámicos.

## Descripción

Este proyecto implementa un controlador de tira LED WS2812B que genera un efecto de desplazamiento de color tipo arcoíris. Utiliza la biblioteca FastLED para el control de los LEDs y TaskScheduler para la gestión de tareas asíncronas.

## Hardware Requerido

- **NodeMCU v2** (ESP8266)
- **Tira LED WS2812B** (30 LEDs)
- Fuente de alimentación adecuada para la tira LED
- Cables de conexión

## Conexiones

- **Pin de datos LED**: D4 (GPIO2)
- **Alimentación**: Conectar 5V y GND a la tira LED
- **Capacitor**: Recomendado 1000µF entre 5V y GND para estabilizar el voltaje

## Dependencias

El proyecto utiliza las siguientes bibliotecas:

- **FastLED** v3.9.16 - Control de tiras LED RGB
- **TaskScheduler** v3.8.5 - Programación de tareas cooperativas

Las dependencias se instalan automáticamente con PlatformIO.

## Configuración

Puedes ajustar los siguientes parámetros en `src/main.cpp`:

```cpp
#define LED_PIN     D4   // Pin de datos para la tira LED
#define NUM_LEDS    30   // Número de LEDs en la tira
#define BRIGHTNESS  128  // Brillo (0-255)
#define COLOR_SPEED 50   // Velocidad de cambio de color en ms
```

## Instalación y Uso

1. **Clonar el repositorio:**
   ```bash
   git clone https://github.com/Itzel-Campos40/Led2.git
   cd Led2
   ```

2. **Abrir en PlatformIO:**
   - Abre el proyecto en Visual Studio Code con la extensión PlatformIO instalada
   - O usa PlatformIO Core desde la línea de comandos

3. **Compilar el proyecto:**
   ```bash
   pio run
   ```

4. **Subir al NodeMCU:**
   ```bash
   pio run --target upload
   ```

## Funcionamiento

El código crea un efecto de arcoíris que se desplaza continuamente a lo largo de la tira LED:

1. Cada LED recibe un color diferente del espectro HSV
2. El matiz se incrementa gradualmente creando el efecto de rotación
3. La actualización se ejecuta cada 50ms usando TaskScheduler

## Estructura del Proyecto

```
Led2/
├── src/
│   └── main.cpp          # Código principal
├── include/              # Archivos de cabecera
├── lib/                  # Bibliotecas locales
├── test/                 # Pruebas unitarias
├── platformio.ini        # Configuración de PlatformIO
├── *.drawio              # Diagramas (clases, flujo, estados, secuencia)
└── README.md             # Este archivo
```

## Diagramas

El proyecto incluye varios diagramas en formato Draw.io:

- `clases.drawio` - Diagrama de clases
- `flujo.drawio` - Diagrama de flujo
- `est.drawio` - Diagrama de estados
- `sec.drawio` - Diagrama de secuencia

## Plataforma

- **Plataforma**: Espressif 8266
- **Framework**: Arduino
- **Board**: NodeMCU v2

## Notas

- Asegúrate de que la tira LED tenga alimentación suficiente (30 LEDs a máximo brillo pueden consumir hasta 1.8A)
- El pin D4 está conectado al LED integrado del NodeMCU, por lo que también parpadeará

## Licencia

Este proyecto es de código abierto y está disponible para uso personal y educativo.

## Autor

**Itzel Campos** - [Itzel-Campos40](https://github.com/Itzel-Campos40)

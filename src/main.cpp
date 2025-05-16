#include <Arduino.h>
#include <FastLED.h>
#include <TaskScheduler.h>

#define LED_PIN     D4  // Pin de datos para la tira LED
#define NUM_LEDS    30  // Número de LEDs en la tira
#define BRIGHTNESS  128 // Brillo (0-255)
#define COLOR_SPEED 50  // Velocidad de cambio de color en ms

CRGB leds[NUM_LEDS];
Scheduler runner;

// Variables para la animación
uint8_t hue = 0;
int8_t delta = 2;  // Incremento del matiz

// Declaración de tareas
void updateLEDsCallback();
Task taskUpdateLEDs(COLOR_SPEED, TASK_FOREVER, &updateLEDsCallback);

void updateLEDsCallback() {
    // Crear efecto de desplazamiento de color
    for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV(hue + (i * 256/NUM_LEDS), 255, 255);
    }
    
    hue += delta; // Rotar colores
    FastLED.show();
}

void setup() {
    // Inicializar FastLED
    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    
    // Inicializar el scheduler y añadir la tarea
    runner.init();
    runner.addTask(taskUpdateLEDs);
    taskUpdateLEDs.enable();
}

void loop() {
    runner.execute();
}
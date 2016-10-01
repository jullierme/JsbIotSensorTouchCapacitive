#include "JsbIotSensorTouchCapacitive.h"

const byte pinLed = 10;
const byte pinRele = 6;
const short luzMinimaParaLedDesligado = 10;
const long sensibilidade = 50;
const byte pinSensorCapacitivo1 = 4;
const byte pinSensorCapacitivo2 = 2;

JsbIotSensorTouchCapacitive sensor = JsbIotSensorTouchCapacitive(pinSensorCapacitivo1,
	pinSensorCapacitivo2, pinRele, pinLed, sensibilidade);

void setup(){
  sensor.ativarLog();
  Serial.begin(115200);
}

void loop(){
  sensor.executar();
  delay(50);
}

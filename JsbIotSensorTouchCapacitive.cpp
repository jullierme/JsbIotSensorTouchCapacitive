/*
*	JsbIotSensorTouchCapacitive.cpp
*	Autor: Jullierme Barros
*/

#include "Arduino.h"
#include "JsbIotSensorTouchCapacitive.h"
#include "CapacitiveSensor.h"

JsbIotSensorTouchCapacitive::JsbIotSensorTouchCapacitive(
	short pinSensorCapacitivo1, short pinSensorCapacitivo2,
	short pinRele, short pinLed, long sensibilidade){

	_pinSensorCapacitivo1 = pinSensorCapacitivo1;
	_pinSensorCapacitivo2 = pinSensorCapacitivo2;
	_pinRele = pinRele;
	_pinLed = pinLed;
	_sensibilidade = sensibilidade;
}

void JsbIotSensorTouchCapacitive::begin(){
	pinMode(_pinLed, OUTPUT);
	pinMode(_pinRele, OUTPUT);

	digitalWrite(_pinRele, _DESLIGA_RELE);

	analogWrite(_pinLed, _luzMinimaParaLedDesligado);

	_cs = CapacitiveSensor(_pinSensorCapacitivo1, _pinSensorCapacitivo2);
	_cs.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void JsbIotSensorTouchCapacitive::ativarLog(){
	_ativarLog = true;
}

void JsbIotSensorTouchCapacitive::desativarLog(){
	_ativarLog = false;
}

void JsbIotSensorTouchCapacitive::setResolucaoSensor(uint8_t resolucaoSensor){
	_resolucaoSensor = resolucaoSensor;
}

uint8_t JsbIotSensorTouchCapacitive::getResolucaoSensor(){
	return _resolucaoSensor;
}

void JsbIotSensorTouchCapacitive::setSensibilidade(long sensibilidade){
	_sensibilidade = sensibilidade;
}

long JsbIotSensorTouchCapacitive::getSensibilidade(){
	return _sensibilidade;
}

long JsbIotSensorTouchCapacitive::getCapacitancia(){
	return _capacitanciaSensor;
}

bool JsbIotSensorTouchCapacitive::isReleAtivado(){
	return _isReleAtivado;
}

CapacitiveSensor JsbIotSensorTouchCapacitive::getSensor(){
	return _cs;
}

void JsbIotSensorTouchCapacitive::executar(){
	_capacitanciaSensor = _cs.capacitiveSensor(_resolucaoSensor);

	if(_ativarLog){
		Serial.print("_capacitanciaSensor ");
		Serial.println(_capacitanciaSensor);
	}


	if (_capacitanciaSensor > _sensibilidade) {
    ativaOuDesativaRele();
  }
}

void JsbIotSensorTouchCapacitive::ativaOuDesativaRele(){
    _isReleAtivado = !_isReleAtivado;

    if (_isReleAtivado){
      acionarRele();
    }
    else{
      desligarRele();
    }
}

void JsbIotSensorTouchCapacitive::controlarLuzLed(int potencia){
  analogWrite(_pinLed, potencia);
  delay(2);
}

void JsbIotSensorTouchCapacitive::acionarRele(){
	if(_ativarLog){
		Serial.print("Acionar relé ");
		Serial.print("Capacitância ");
		Serial.println(_capacitanciaSensor);
	}

  digitalWrite(_pinRele, _ACIONA_RELE);

  for (short i = _luzMinimaParaLedDesligado; i < 255; i++){
    controlarLuzLed(i);
  }
}

void JsbIotSensorTouchCapacitive::desligarRele(){
	if(_ativarLog){
		Serial.println("Desligar relé");
	}

  digitalWrite(_pinRele, _DESLIGA_RELE);

  for (short i = 255; i > _luzMinimaParaLedDesligado; i--){
    controlarLuzLed(i);
  }
}

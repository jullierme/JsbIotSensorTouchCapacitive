/*
*	JsbIotSensorTouchCapacitive.h
*	Autor: Jullierme Barros
*/

#ifndef JsbIotSensorTouchCapacitive_h
#define JsbIotSensorTouchCapacitive_h

#include "Arduino.h"
#include "CapacitiveSensor.h"

/*Ao adicionar um método aqui, add também em keywords.txt*/
class JsbIotSensorTouchCapacitive{
	public:
		JsbIotSensorTouchCapacitive(short pinSensorCapacitivo1,
			short pinSensorCapacitivo2, short pinRele, short pinLed,
			long sensibilidade);
		void ativarLog();
		void desativarLog();
		void setSensibilidade(long sensibilidade);
		long getSensibilidade();
		long getCapacitancia();
		bool isReleAtivado();
		short getLuzMinimaParaLedDesligado();
		void setLuzMinimaParaLedDesligado(short luzMinimaParaLedDesligado);
		void executar();

		void ativaOuDesativaRele();
		void acionarRele();
		void desligarRele();

	private:
		short _pinSensorCapacitivo1;
		short _pinSensorCapacitivo2;
		short _pinRele;
		short _pinLed;
		long _sensibilidade;
		bool _ativarLog;
		short _luzMinimaParaLedDesligado = 10;
		short _ACIONA_RELE = LOW;
		short _DESLIGA_RELE = HIGH;
		long _capacitanciaSensor;
		bool _isReleAtivado = false;
		CapacitiveSensor _cs = CapacitiveSensor(4,5);


		void controlarLuzLed(int potencia);

};

#endif

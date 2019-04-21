#include "DualCoreClass.h"

void SimulacaoProcessamento() {
	unsigned long loops1 = 1000;
	unsigned long loops2 = 1000;

	float calculoFloat_1;
	int calculoInt_1;
	int calculoInt_2;

	unsigned long contador = 0;
	for (long i = 0; i < loops1; i++) {
		for (long j = 1; j < loops2; j++) {
			contador++;
			calculoFloat_1 = 5000.0 * i;
			calculoInt_1 = 150 * 1234 * i;
			calculoInt_2 = j % 554;
		}
	}
}

void loopCore_0() {
	long inicio = millis();

	SimulacaoProcessamento();

	Serial.print("Tarefa 1 finalizada no Core: ");
	Serial.print(xPortGetCoreID());
	Serial.print(" Tempo: ");
	Serial.println(millis() - inicio);
	delay(10);
}

void loopCore_1() {
	long inicio = millis();

	SimulacaoProcessamento();

	Serial.print("Tarefa 2 finalizada no Core: ");
	Serial.print(xPortGetCoreID());
	Serial.print(" Tempo: ");
	Serial.println(millis() - inicio);
	delay(10);
}

void setup() {
	Serial.begin(115200);
	auto DualCore = new DualCoreClass(loopCore_0, loopCore_1);
}

void loop() { //Executa no Core 1
	delay(1000);
}

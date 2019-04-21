#include "DualCoreClass.h"

void tempo_para_inicializar_tarefa()
{
	delay(500);
};

void loop_tarefa_0(void * parametro)
{
	while (true)
	{
		tarefa_core_0();
	}
}

void loop_tarefa_1(void * parametro)
{
	while (true)
	{
		tarefa_core_1();
	}
}

DualCoreClass::DualCoreClass(const tarefa_core tarefa_0, const tarefa_core tarefa_1)
{
	tarefa_core_0 = tarefa_0;
	tarefa_core_1 = tarefa_1;
	xTaskCreatePinnedToCore(
		loop_tarefa_0,
		"tarefa_0",
		1000,
		nullptr,
		1,
		&tarefa_core_0_,
		0);

	tempo_para_inicializar_tarefa();

	xTaskCreatePinnedToCore(
		loop_tarefa_1,
		"tarefa_1",
		1000,
		nullptr,
		1,
		&tarefa_core_1_,
		1);
}

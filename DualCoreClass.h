#pragma once

typedef void(*tarefa_core)();
static tarefa_core tarefa_core_0;
static tarefa_core tarefa_core_1;

class DualCoreClass
{
	TaskHandle_t tarefa_core_0_;
	TaskHandle_t tarefa_core_1_;
public:
	DualCoreClass(tarefa_core t0, tarefa_core t1);
};

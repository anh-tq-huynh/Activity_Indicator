#include <iostream>
#include "FreeRTOS.h"
#include "task.h"
#include "incl/TaskBlinker.h"
#include "incl/Semaphore.h"
#include "incl/TaskRead.h"
#include "incl/vPrintString.h"
#include "pico/stdio.h"

#define D1 22
#define D2 21
#define D3 20

// stack overflow check
extern "C" {
	void vApplicationStackOverflowHook( TaskHandle_t xTask, char * pcTaskName ) {
		if (pcTaskName != NULL) panic("Stack overflow: %s",pcTaskName);
		else panic("Stack overflow of unnamed task");
	}
}

#include "hardware/timer.h"
extern "C" {
	uint32_t read_runtime_ctr(void) {
		return timer_hw->timerawl;
	}
}

int main ()
{
	stdio_init_all();
	vPrintString("Program starts!\n");
	vPrintString("Type: ");
	Semaphore sem;

	static TaskRead reader(sem);
	static TaskBlinker blinker(D1,sem);

	vTaskStartScheduler();
	while (true)
	{

	}
}

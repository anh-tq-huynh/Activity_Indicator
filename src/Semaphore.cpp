//
// Created by Anh Huynh on 6.9.2026.
//

#include "../incl/Semaphore.h"

Semaphore::Semaphore()
{
	binary_semaphore = xSemaphoreCreateBinary();
}

void Semaphore::receive()
{
	xSemaphoreTake(binary_semaphore, pdMS_TO_TICKS(200));
}

void Semaphore::send()
{
	xSemaphoreGiveFromISR(binary_semaphore, &HigherPriorityTaskWoken);
}




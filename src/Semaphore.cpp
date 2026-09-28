//
// Created by Anh Huynh on 6.9.2026.
//

#include "../incl/Semaphore.h"

Semaphore::Semaphore()
{
	binary_semaphore = xSemaphoreCreateBinary();
	semaphore_status = pdFALSE;
}

void Semaphore::take()
{
	semaphore_status = xSemaphoreTake(binary_semaphore, portMAX_DELAY);
}

void Semaphore::give() const
{
	xSemaphoreGive(binary_semaphore);
}

bool Semaphore::sem_available() const
{
	return semaphore_status == pdPASS;
}




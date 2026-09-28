//
// Created by Anh Huynh on 6.9.2026.
//

#include "../incl/TaskRead.h"

#include <string>

#include "incl/vPrintString.h"
#include "pico/stdio.h"


void TaskRead::read_serial_port()
{
	while (true)
	{
		int c = getchar_timeout_us(0);
		if (c != PICO_ERROR_TIMEOUT)
		{
			vPrintString("\nEcho: ");
			stdio_putchar(c);
			vPrintString("\n");
			semaphore.give();
		}
		else
		{
			vTaskDelay(pdMS_TO_TICKS(10));
		}
	}
}

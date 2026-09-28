//
// Created by Anh Huynh on 6.9.2026.
//

#include "../TaskBlinker.h"

void TaskBlinker::blink() const
{
	while (true)
	{
		semaphore.take();

		led.led_on();
		vTaskDelay(pdMS_TO_TICKS(100));

		led.led_off();
		vTaskDelay(pdMS_TO_TICKS(100));
	}
}



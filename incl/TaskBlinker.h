//
// Created by Anh Huynh on 6.9.2026.
//

#ifndef LAB3_1_TASKBLINKER_H
#define LAB3_1_TASKBLINKER_H
#include "LED.h"
#include "Semaphore.h"


class TaskBlinker
{
	public:
		TaskBlinker(int led, Semaphore &semaphore) : led (led), semaphore(semaphore)
		{
			xTaskCreate(blinker, "Blinker",512, (void *) this, tskIDLE_PRIORITY + 1, &handle);
		};
		void blink() const;
	private:
		static void blinker(void *param)
		{
			auto *instance = static_cast<TaskBlinker *> (param);
			instance -> blink();
		}
		LED led;
		Semaphore &semaphore;
		TaskHandle_t handle;
};


#endif //LAB3_1_TASKBLINKER_H
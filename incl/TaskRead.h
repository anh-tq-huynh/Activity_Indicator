//
// Created by Anh Huynh on 6.9.2026.
//

#ifndef LAB3_1_TASKREAD_H
#define LAB3_1_TASKREAD_H
#include "Semaphore.h"
#include "semphr.h"


class TaskRead
{
	public:
		TaskRead ( Semaphore &semaphore) : semaphore(semaphore)
		{
			xTaskCreate(reader, "Reader", 512, (void * )this, tskIDLE_PRIORITY + 1, &handle);
		};
		void read_serial_port();
	private:
		Semaphore &semaphore;
		static void reader (void *param)
		{
			auto *instance = static_cast<TaskRead *> (param);
			instance -> read_serial_port();
		}
		TaskHandle_t handle;
};


#endif //LAB3_1_TASKREAD_H
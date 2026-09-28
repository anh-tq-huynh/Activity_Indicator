//
// Created by Anh Huynh on 6.9.2026.
//

#ifndef LAB3_1_SEMAPHORE_H
#define LAB3_1_SEMAPHORE_H
#include "FreeRTOS.h"
#include "semphr.h"


class Semaphore
{
	public:
		Semaphore();
		virtual ~Semaphore() = default;
		void give() const;

		bool sem_available() const;

		void take();
	private:
		SemaphoreHandle_t binary_semaphore;
		BaseType_t semaphore_status;
};


#endif //LAB3_1_SEMAPHORE_H
# Summary
A program that creates two tasks: one for reading characters from the serial port and the other for
indicating received characters on the serial port. Use a binary semaphore to notify serial port activity to the
indicator task.

# Tasks requirements
### Task 1
Task reads characters from debug serial port using getchar_timeout_us and echoes them back to the serial
port. When a character is received the task sends an indication (= gives the binary semaphore) to blinker
task. The timeout on calls to getchar_timeout_us must be set to zero because the function does not use
FreeRTOS and a non-zero timeout will be handled in a busy wait loop. Use vTaskDelay to release CPU time
to other tasks when no characters are received. Delay a bit when no character was received and if a
character was received just loop back to receive without delay to ensure that you catch all received
characters.
### Task 2
This task blinks the led once (100 ms on, 100 ms off) when it receives activity indication (= takes the binary
semaphore).

# FreeRTOS kernel mechanism
- Task
- Semaphore

# Hardware
The program was implemented on Raspberry Pi Pico W

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "led/bsp_led.h"

osThreadId_t LEDTaskHandle;
const osThreadAttr_t LEDTask_attributes =
{
  .name = "LEDTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t)osPriorityNormal,
};

osThreadId_t SerialTaskHandle;
const osThreadAttr_t SerialTask_attributes =
{
  .name = "SerialTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t)osPriorityLow,
};

void StartLEDTask(void *argument)
{
  while (1)
  {
		LED_On(LED_RED);
		LED_Off(LED_BLUE);
    osDelay(300);

		LED_Off(LED_RED);
		LED_On(LED_GREEN);
    osDelay(300);

		LED_Off(LED_GREEN);
		LED_On(LED_BLUE);
    osDelay(300);
  }
}

void StartSerialTask(void *argument)
{
	uint32_t count = 1;

  while (1)
  {
		printf("Hello world! * %d\r\n", count++);
    osDelay(1000);
  }
}

void FREERTOS_Init(void)
{
  LEDTaskHandle = osThreadNew(StartLEDTask, NULL, &LEDTask_attributes);
	if (LEDTaskHandle == NULL)
	{
		Error_Handler();
	}

	SerialTaskHandle = osThreadNew(StartSerialTask, NULL, &SerialTask_attributes);
	if (SerialTaskHandle == NULL)
	{
		Error_Handler();
	}
}

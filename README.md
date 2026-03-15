# stm32f103-template
基于 HAL 库的 STM32F103 工程模板，包含：
1. STM32F103_Template：手动创建的裸机工程模板，使用 SysTick 作为 HAL 库的时基
2. STM32F103_Template_FreeRTOS：手动创建的带 FreeRTOS 的工程模板，使用 TIM4 作为 HAL 库的时基，SysTick 留给 FreeRTOS 使用

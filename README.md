# STM32F401 Drivers

Driver layer (MCAL + HAL) for the STM32F401 written without ST's HAL — every register I/O is explicit. Built it during the embedded-systems phase of my degree to internalize Cortex-M4 instead of memcpy'ing demo code.

Covers: GPIO, UART (with ring buffer), SPI, I²C master, NVIC, system clock setup, basic timers, ADC.

Used by my `Bootloader` repo.

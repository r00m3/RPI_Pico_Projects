#include "pico/stdlib.h"

int LED = 0;

void handle_LED_selection()
{
	// Turn OFF all LEDs.
	gpio_put(0, false);
	gpio_put(1, false);
	gpio_put(2, false);
	// Turn ON the selected LED.
	if (LED == 0)
	{
		gpio_put(0, true);
	}
	else if (LED == 1)
	{
		gpio_put(1, true);
	}
	else if (LED == 2)
	{
		gpio_put(2, true);
	}
	// Increment the LED selection.
	if (LED >= 2)
	{
		LED = 0;
	}
	else
	{
		LED += 1;
	}
}

int main()
{
	stdio_init_all();
	// Init LED outputs.
	{
		// LED Red.
		gpio_init(0);
		gpio_set_drive_strength(0, GPIO_DRIVE_STRENGTH_2MA);
		gpio_set_dir(0, GPIO_OUT);

		// LED Green.
		gpio_init(1);
		gpio_set_drive_strength(1, GPIO_DRIVE_STRENGTH_2MA);
		gpio_set_dir(1, GPIO_OUT);

		// LED Yellow.
		gpio_init(2);
		gpio_set_drive_strength(2, GPIO_DRIVE_STRENGTH_2MA);
		gpio_set_dir(2, GPIO_OUT);
	}
	// Init Input.
	{
		// Button cycles lighted up LEDs.
		gpio_init(3);
		gpio_set_dir(3, GPIO_IN);
		gpio_pull_up(3);
	}
	while (true)
	{
		// Check if button pressed.
		if (!gpio_get(3))
		{
			handle_LED_selection();
			// Set polling rate.
			sleep_ms(150);
		}
	}
}
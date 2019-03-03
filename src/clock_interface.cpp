/*
 * Author: Daniel Christiansen
 */

#include "clock_interface.h"

void ClockInterface::init() {

	// turn on port a clock
	SIM_SCGC5 |= SIM_SCGC5_PORTA;

	// configure pin settings
	PORTA_PCR1 |=
		(PORT_PCR_IRQC(10)	// enable falling-edge interrupts
		|PORT_PCR_MUX(1)	// set pin mode to GPIO
		|PORT_PCR_PE			// enable pull resistor
		|PORT_PCR_PS			// set pull-up resistor
		);

	// setup for clock interrupt on pin 3 (port A1)
	//NVIC_SET_PRIORITY(IRQ_PORTA, 0);
	NVIC_ENABLE_IRQ(IRQ_PORTA);

	


}

// sets pwm period
void ClockInterface::set() {

	// set pwm period
	//TPM0_MOD = ??;

	// set pwm compare

}



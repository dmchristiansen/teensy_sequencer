#include "WProgram.h"
#include "controller.h"
#include "ui.h"
#include "system.h"

SequenceController controller;
UI ui;


extern "C" int main(void)
{
	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);

	ui.init();
	controller.init(&ui);

	while (1) {}


}

void systick_isr(void) {

	// poll system
	ui.poll();

}

void porta_isr(void) {
	
	// check if the interrupt was on pa1
	if (PORTA_ISFR & 0x2) {
		PORTA_ISFR = 0x00000002;		// clear interrupt
		controller.advance();	// respond to clock edge
	}

}


/*
 * Program flow:
 *
 * systick (1kHz) triggers controller to assess state
 * - on clk interrupt pending, 
 *   - advance step
 *   - update nominal step period
 *   - clean read from ui
 *   - update state
 * - on no interrupt, 
 *   - update read from ui
 *   - update state
 *
 * ui state update:
 * 	- read from cv_input
 * 	 - read waiting adc conversion
 * 	 - start next conversion
 * 	 - map & lpf cv inputs
 * 	- read from switch_input
 * 	 - scan through switch inputs, interpret result
 *
 *
 *
 */

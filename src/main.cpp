


#include "WProgram.h"
#include "controller.h"
#include "ui.h"
#include "system.h"
#include "Arduino.h"

void ms_tick(void);

SequenceController controller;
UI ui;
ControlState control_state;

extern "C" int main(void)
{
	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);

	//Serial.begin(115200);

	ui.init(&control_state);
	controller.init(&ui, &control_state);

	// reassign systick interrupt
	_VectorsRam[15] = &ms_tick;

	while (1) {
		//delay(10);
		//Serial.println(*(uint16_t*)&ADC0_RA);
	}

}

// 1ms tick, scans input & updates current state
void ms_tick(void) {

	systick_millis_count++;

	ui.poll();
	controller.update();

}

void porta_isr(void) {
	
	// check if the interrupt was on PTA1
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

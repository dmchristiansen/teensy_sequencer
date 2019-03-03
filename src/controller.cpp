/*
 * Author: Daniel Christiansen
 */

#include "controller.h"

void SequenceController::init(UI* ui_, ControlState* state_) {

	state = state_;
	ui = ui_;
	clock.init();
	dac.init();

	state->clock_freq = 0;
	state->pulse_width = 0;		// width of gate pulse in ms
	state->slide_time = 0;
	state->beat_count = 0; 		// 0, 1, 2, 4
	state->gate_mode = 0;			// off, single, multiple, continuous
	state->target_pitch = 0;	// sort-of volts
	state->current_period = 0;// ms in current step
	state->step = 0;			// current sequence step
	
	// pins 2, 7, 8, 6, 5 on the teensy LC map to 
	// pins PORTD 0, 2, 3, 4, 7 respectively

	// enable PORTD clock
	SIM_SCGC5 |= SIM_SCGC5_PORTD;

	// set pins to GPIO mode
	PORTD_PCR0 |= PORT_PCR_MUX(1);
	PORTD_PCR2 |= PORT_PCR_MUX(1);	
	PORTD_PCR3 |= PORT_PCR_MUX(1);	
	PORTD_PCR4 |= PORT_PCR_MUX(1);
	PORTD_PCR7 |= PORT_PCR_MUX(1);

	// set pins to output
	GPIOD_PDDR |= 0x9D;

}

// updates system state within each step, called every 1ms
void SequenceController::update() {

	dac.write(state->target_pitch);	
	//analogWrite(A12, state->target_pitch);

	// update gate output
	// currently tracks external clock level,
	// will eventually be adjustable
	if (GPIOA_PDIR & 0x2) {
		digitalWrite(13, LOW);
		GPIOD_PCOR = 0x1;
	} else {
		digitalWrite(13, HIGH);
		GPIOD_PSOR = 0x1;
	}

	//state->current_period++;
}

// responds to clock edge
void SequenceController::advance() {

	// advance to next step based on step settings
	// (more complex once buttons are incorporated)
	step = (step + 1) % 8;
	state->step = step;

	// change step-mux select lines
	// on the cd4051, pins C,B,A connect to PORTD 4,3,2
	GPIOD_PDOR = (GPIOD_PDDR & 0xFFFFFFE3) | ((step & 0x7) << 2);	

	// update with new step values
	ui->refresh();
	update();

	nom_period = state->current_period;
	state->current_period = 0;

	// generate gate signal
	GPIOD_PSOR = 0x1;

}

// resets to first step
void SequenceController::reset() {

}


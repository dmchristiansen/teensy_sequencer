/*
 *
 */

#include "cv_input.h"

void CVInput::init(ControlState* state_) {

	state = state_;

	// set up adc
	adc.init();	
	adc_state = 0;
}

void CVInput::scan() {

	// read result of previous conversion
	int32_t raw_val = adc.readValue();
	if (raw_val != -1) {
		pots_raw[adc_state] = static_cast<uint16_t>(raw_val & 0xFFFF);
	}


	// map value based on which pin it is...
	// just map pitch pot for now...
	// 16 bit ADC, 12 bit DAC
	pots_mapped[adc_state] = (pots_raw[adc_state]);	

	// low-pass filter on mapped readings
	for (int32_t i = 0; i < pin_count; i++) {
		pots_lp[i] += (pots_mapped[i] - pots_lp[i]) >> pin_map[i].lp_shift; 
	}

	// start next conversion
	if (raw_val != -1) {
		adc_state = (adc_state + 1) % pin_count;
		adc.startSingleRead(pin_map[adc_state].pin);
	}

	// update state
	if (state) {
		cli();
		state->target_pitch = static_cast<uint16_t>(pots_lp[PITCH_POT]);
		sei();
	}
}

// updates target pitch, doesn't filter value.
// this should be called at the start of a new step
// to quickly get the next pitch.
void CVInput::pitch() {

	// blocking read
	int32_t raw_val = adc.analogRead(pin_map[PITCH_POT].pin);

	// restart previous conversion
	adc.startSingleRead(pin_map[adc_state].pin);
	
	// this shouls map the pitch in some way, once that's implemented
	pots_lp[PITCH_POT] = raw_val & 0xFFFF;
	state->target_pitch = static_cast<uint16_t>(raw_val & 0xFFFF);

}


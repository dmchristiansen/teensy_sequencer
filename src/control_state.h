/*
 * Author: Daniel Christiansen
 */

#ifndef CONTROL_STATE_H
#define CONTROL_STATE_H

#include "system.h"

struct ControlState {
	volatile float clock_freq; 	// Hz
	volatile float pulse_width; 	// [0, 1)
	volatile float slide_time; 	// [0, 1]
	volatile uint8_t beat_count; // 0, 1, 2, 4
	volatile uint8_t gate_mode;	// off, single, multiple, continuous
	volatile uint16_t target_pitch;	// sort-of volts
	volatile uint32_t current_period;	// ms in current step
	volatile uint32_t target_period;	// desired ms in step
	volatile uint8_t step;			// current sequence step
};

#endif


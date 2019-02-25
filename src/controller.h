/*
 * Author: Daniel Christiansen
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "system.h"
#include "ui.h"
#include "clock_interface.h"

struct StepState {
	uint8_t beat_count; // 0, 1, 2, 4
	uint8_t gate_mode;
	float target_pitch; // Hz
};

struct ControlState {
	float clock_freq; // Hz
	float pulse_width; // [0, 1)
	float slide_time; // [0, 1]
};

class SequenceController {

	private:

		int led_flag = 0;
		UI* ui_;
		ClockInterface clock;		
		ControlState control_ = {0};
		uint8_t step;

		StepState state_[8] = {{0}};
		uint8_t beat_count;
		float current_pitch;
		float nom_period;

	public:

		SequenceController() {};
		~SequenceController() {};
		void init(UI*);

		void update();
		void advance();
		void reset();

};


#endif


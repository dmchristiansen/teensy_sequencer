/*
 * Author: Daniel Christiansen
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "system.h"
#include "ui.h"
#include "clock_interface.h"
#include "control_state.h"
#include "dac_module.h"

class SequenceController {

	private:

		int led_flag = 0;

		UI* ui = 0;
		ClockInterface clock;		
		ControlState* state = 0;
		DACModule dac;
		uint32_t step;

		uint8_t beat_count;
		float current_pitch;
		float nom_period;

	public:

		SequenceController() {};
		~SequenceController() {};
		void init(UI*, ControlState*);

		void update();
		void advance();
		void reset();

};


#endif


/*
 * Author: Daniel Christiansen
 */

#ifndef CV_INPUT_H
#define CV_INPUT_H

#include "system.h"
#include "adc_module.h"
#include "control_state.h"

enum pot_map {
	PITCH_POT = 0
};

struct pinMap {
	uint8_t pin;
	int32_t lp_shift;
};

class CVInput {

	private:
		int count = 0;

		ADCModule adc;
		ControlState* state = 0;

		int32_t adc_state = 0;
		static const int32_t pin_count = 1;
		pinMap pin_map[pin_count] = {
			{11, 2}		// pitch pots
		};

		uint16_t pots_raw[pin_count] = {0};
		uint16_t pots_mapped[pin_count] = {0};
		uint16_t pots_lp[pin_count] = {0};

	public:

		CVInput() {};
		~CVInput() {};
		void init(ControlState*);

		void scan();
		void pitch();

};


#endif


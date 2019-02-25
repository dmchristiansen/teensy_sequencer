/*
 * Author: Daniel Christiansen
 */

#ifndef CV_INPUT_H
#define CV_INPUT_H

#include "system.h"
#include <ADC.h>

class CVInput {

	private:

		ADC adc;

	public:

		CVInput() {};
		~CVInput() {};
		void init();

		void scan();
		void read();

};


#endif


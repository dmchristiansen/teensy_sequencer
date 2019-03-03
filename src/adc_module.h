/*
 * Author: Daniel Christiansen
 */

#ifndef ADC_MODULE_H
#define ADC_MODULE_H

#include "system.h"

class ADCModule {

	private:
	
	public:

		ADCModule() {};
		~ADCModule() {};

		void init();
		int32_t startSingleRead(uint8_t);
		int32_t readValue();
		int32_t analogRead(uint8_t);

};

#endif


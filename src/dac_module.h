/*
 * Author: Daniel Christiansen
 */

#ifndef DAC_MODULE_H
#define DAC_MODULE_H

#include "system.h"

class DACModule {

	private:


	public:

		DACModule() {};
		~DACModule() {};
		
		void init();
		void write(uint16_t value) {*(int16_t*)&DAC0_DAT0L = value;};

};

#endif


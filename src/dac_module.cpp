/*
 * Author: Daniel Christiansen
 */

#include "dac_module.h"

void DACModule::init() {

	// start DAC clock
	SIM_SCGC6 |= SIM_SCGC6_DAC0;

	DAC0_C0 = 
		(DAC_C0_DACEN		// enable DAC
		|DAC_C0_DACRFS	// reference select
		);
}


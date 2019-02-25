/*
 *
 */

#include "cv_input.h"

void CVInput::init() {

	// set up adc
	adc.setAveraging(16);
	adc.setResolution(16);
	adc.setConversionSpeed(ADC_CONVERSION_SPEED::HIGH_SPEED);

	
}

void CVInput::scan() {

}

void CVInput::read() {

}


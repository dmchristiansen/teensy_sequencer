/*
 *
 */

#include "adc_module.h"

void ADCModule::init() {

	// start ADC module clock
	SIM_SCGC6 |= SIM_SCGC6_ADC0;

	ADC0_CFG1 =
		(ADC_CFG1_ADIV(0)	// set clock division
		|ADC_CFG1_ADLSMP	// set long conversion time
		|ADC_CFG1_MODE(1)	// set 12-bit conversion mode
		);

	ADC0_SC3 =
		(ADC_SC3_AVGE			// enable hw averaging
		|ADC_SC3_AVGS(2)	// 32 sample average
 		);		
 
	// calibration sequence
	while (1) {
		ADC0_SC3 |= ADC_SC3_CAL;  // start calibration
		while (ADC0_SC3 & ADC_SC3_CAL) {}; // wait for completion
		if (!(ADC0_SC3 & ADC_SC3_CALF)) break; // if sucessful, end sequence
	}

}

// starts a read on specified pin
int32_t ADCModule::startSingleRead(uint8_t pin) {

	// check for active conversion
	if (ADC0_SC2 & ADC_SC2_ADACT)
		return -1;

	// set input channel to correct pin & start conversion
	ADC0_SC1A = (ADC0_SC1A & 0xFFFFFFE0) | (pin & 0x1F);

	return 0;

}

int32_t ADCModule::readValue() {

	// check for completed conversion
	if (!(ADC0_SC1A & ADC_SC1_COCO))
		return -1;

	// return result
	uint16_t result = *(uint16_t*)&ADC0_RA;
	return static_cast<int32_t>(result);

}

// blocking read
int32_t ADCModule::analogRead(uint8_t pin) {

	bool restore = false;
	uint32_t temp;

	// if a conversion is in progress,
	// save configuration and halt
	if (ADC0_SC2 & ADC_SC2_ADACT) {
		temp = ADC0_SC1A;
		ADC0_SC1A = 0x0;
		restore = true;
	}
	
	// set input channel to correct pin & start conversion
	ADC0_SC1A = (ADC0_SC1A & 0xFFFFFFE0) | (pin & 0x1F);
	
	// wait until conversion is complete
	while(!(ADC0_SC1A & ADC_SC1_COCO)) {}

	int32_t result = ADC0_RA;
	if (restore) ADC0_SC1A = temp;
	return result;
	
}


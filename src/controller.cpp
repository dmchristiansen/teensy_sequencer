/*
 * Author: Daniel Christiansen
 */

#include "controller.h"

void SequenceController::init(UI* ui) {

	ui_ = ui;
	clock.init();

}

// updates system state within each step, called every 1ms
void SequenceController::update() {

}

// responds to clock edge
void SequenceController::advance() {

	led_flag = ~led_flag;
	digitalWrite(13, led_flag ? HIGH : LOW);

}

// resets to first step
void SequenceController::reset() {

}


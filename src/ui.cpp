/*
 * Author: Daniel Christiansen
 *
 */

#include "ui.h"

void UI::init(ControlState* state_) {

	state = state_;
	cv_.init(state);
	switch_.init();

}

// polls inputs
void UI::poll() {

	// read pots
	cv_.scan();
	switch_.scan(state);

}

// polls pitch pot & switches
void UI::refresh() {

	cv_.pitch();
	switch_.scan(state);

}


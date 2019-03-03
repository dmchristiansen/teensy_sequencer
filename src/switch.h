/*
 * Author: Daniel Christiansen
 */

#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

#include "system.h"
#include "control_state.h"

class SwitchInterface {

	private:

	
	public:

		SwitchInterface() {};
		~SwitchInterface() {};
		void init();

		uint8_t scan(ControlState*);

};

#endif


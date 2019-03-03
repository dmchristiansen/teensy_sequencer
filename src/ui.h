/*
 * Author: Daniel Christiansen
 */

#ifndef UI_H
#define UI_H

#include "system.h"
#include "cv_input.h"
#include "switch.h"
#include "control_state.h"

class UI {

	private:
	
		CVInput cv_;
		SwitchInterface switch_;
		ControlState* state = 0;

	public:

		UI() {};
		~UI() {};
		void init(ControlState*);

		void poll();
		void refresh();

};

#endif


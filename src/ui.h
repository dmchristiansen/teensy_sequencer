/*
 * Author: Daniel Christiansen
 */

#ifndef UI_H
#define UI_H

#include "system.h"
#include "cv_input.h"
#include "switch.h"

struct StepState;
struct ControlState;

class UI {

	private:
	
		CVInput cv_;
		SwitchInterface switch_;

	public:

		UI() {};
		~UI() {};
		void init();

		void poll();
		void read(StepState*, ControlState*);

};

#endif


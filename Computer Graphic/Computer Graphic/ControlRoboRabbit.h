#pragma once
#include "RoboRabbit.h"

class ControlRoboRabbit : RoboRabbit {
private:
	void Action() {
		while (Work) {
			Poisoning();
			Heartbeat();
			Rotation();
			Moving();
		}
	}
public:
	void Control() {
		thread thread1(&ControlRoboRabbit::Action, this);
		while (1) {
			int action;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "Input command: ";
			cin >> action;
			switch (action) {
			case 0:
				HeartbeatWork = false;
				RotationWork = false;
				PoisoningWork = false;
				MovingWork = true;
				break;
			case 1:
				HeartbeatWork = false;
				RotationWork = false;
				PoisoningWork = true;
				MovingWork = false;
				break;
			case 2:
				HeartbeatWork = true;
				RotationWork = false;
				PoisoningWork = false;
				MovingWork = false;
				break;
			case 3:
				RotationWork = true;
				PoisoningWork = false;
				HeartbeatWork = false;
				MovingWork = false;
				break;
			default:
				RotationWork = false;
				PoisoningWork = false;
				HeartbeatWork = false;
				MovingWork = false;
				Work = 0;
				thread1.join();
				return;
			}
		}
	}
};
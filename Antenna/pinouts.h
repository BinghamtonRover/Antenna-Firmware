#ifndef PINOUTS_H
#define PINOUTS_H

#include "src/tmc/BURT_TMC.h"

StepperMotorPins swivel_pins = {
	enable: 1,  // pinouts unknown- placeholder 1
	chipSelect: 1,  // pinouts unknown- placeholder 1
};
StepperMotorConfig swivel_config = {
	name: "swivel",
	current: 2000,
	speed: 200'000,
	acceleration: 200'000,
	stepsPerUnit: microstepsPerRadian * 47,
};

StepperMotorPins pitch_pins = {
	enable: 1,  // pinouts unknown- placeholder 1
	chipSelect: 1,  // pinouts unknown- placeholder 1
};
StepperMotorConfig pitch_config = {
    name: "swivel",
	current: 2000,
	speed: 200'000,
	acceleration: 200'000,
	stepsPerUnit: microstepsPerRadian * 47,
};


StepperMotor swivel(swivel_pins, swivel_config);
StepperMotor swivel(pitch_pins, pitch_config);

#endif
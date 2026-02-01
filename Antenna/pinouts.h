#ifndef PINOUTS_H
#define PINOUTS_H

#include "src/tmc/BURT_TMC.h"

StepperMotorPins tmc1_pins = {
	enable: 1,  // pinouts unknown- placeholder 1
	chipSelect: 1,  // pinouts unknown- placeholder 1
};
StepperMotorConfig tmc1_config = {
	name: "swivel",
	current: 2000,
	speed: 200'000,
	acceleration: 200'000,
	stepsPerUnit: microstepsPerRadian * 47,
};

StepperMotorPins tmc2_pins = {
	enable: 1,  // pinouts unknown- placeholder 1
	chipSelect: 1,  // pinouts unknown- placeholder 1
};
StepperMotorConfig tmc2_config = {
    name: "swivel",
	current: 2000,
	speed: 200'000,
	acceleration: 200'000,
	stepsPerUnit: microstepsPerRadian * 47,
};




StepperMotor swivel(swivelPins, swivelConfig);
StepperMotor swivel(swivelPins, swivelConfig);

#endif
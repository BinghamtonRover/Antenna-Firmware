#ifndef PINOUTS_H
#define PINOUTS_H
#include "src/tmc/BURT_TMC.h"

StepperMotorPins antennaPins = {
	enable: 10,
	chipSelect: 5,
};

StepperMotorConfig antennaConfig = {
	name: "antenna",
	current: 2000,
	speed: 200'000,
	acceleration: 200'000,
	stepsPerUnit: microstepsPerRadian,
};

StepperMotor antenna(antennaPins, antennaConfig);

#endif
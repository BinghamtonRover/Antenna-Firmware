#ifndef PINOUTS_H
#define PINOUTS_H
#include "src/tmc/BURT_TMC.h"

StepperMotorPins antennaPins = {
	enable: 10,
	chipSelect: 10,
};

StepperMotorConfig antennaConfig = {
	name: "antenna",
	current: 2000,
	speed: 60'000,
	acceleration: 200'000,
	stepsPerUnit: microstepsPerRadian * 20,
};

StepperMotor antenna(antennaPins, antennaConfig);

#endif
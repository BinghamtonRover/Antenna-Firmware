#ifndef PINOUTS_H
#define PINOUTS_H

#include "src/tmc/BURT_TMC.h"   // using internal ramp mode on step-dir-mode branch, not main branch


StepperGeneralConfig swivelGeneralConfig = {
  name: "swivel",
  steps_per_unit: microsteps_per_radian * 47,
};

StepperMotorPins swivelMotorPins = {
  chip_select: 1,   // pinouts unknown- placeholder 1
  step_pin: 1,      // pinouts unknown- placeholder 1
  dir_pin: 1,       // pinouts unknown- placeholder 1
};

InternalRampConfig swivelInternalRampConfig = {
    current: 2000,
    speed: 200'000,
    acceleration: 200'000,
};



StepperGeneralConfig pitchGeneralConfig = {
  name: "pitch",
  steps_per_unit: microsteps_per_radian * 47,
};

StepperMotorPins pitchMotorPins = {
    chip_select: 1,   // pinouts unknown- placeholder 1
    step_pin: 1,      // pinouts unknown- placeholder 1
    dir_pin: 1,       // pinouts unknown- placeholder 1
};

InternalRampConfig pitchInternalRampConfig = {
    current: 2000,
    speed: 200'000,
    acceleration: 200'000,
};



StepperMotor swivel(swivelGeneralConfig, swivelMotorPins, swivelInternalRampConfig);
StepperMotor pitch(pitchGeneralConfig, pitchMotorPins, pitchInternalRampConfig);

#endif
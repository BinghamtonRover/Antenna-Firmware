#include "src/utils/BURT_utils.h"
#include "src/tmc/BURT_TMC.h"
#include "src/base_station.pb.h"
#include "src/motor.pb.h"
#include "src/utils/core.pb.h"
#include "pinouts.h"

// TODO: Add AntennaCommand, AntennaData, and Device.ANTENNA to burt_network
// TODO: Add BurtSerial to communicate with the Dashboard

#define DATA_SEND_INTERVAL 250  // ms

Version version = { major: 1, minor: 0 };

void handleCommand(const uint8_t* buffer, int length);
void sendData();

BurtSerial serial(Device::Device_ANTENNA, handleCommand, AntennaFirmwareData_fields, AntennaFirmwareData_size);
BurtTimer dataTimer(DATA_SEND_INTERVAL, sendData);

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing MARS subsystem");
  Serial.println("Initializing software...");
  serial.setup();
  dataTimer.setup();
  Serial.println("Done!");

  Serial.println("Initializing hardware...");
  antenna.setup();

  Serial.println("MARS subsystem initialized");
}

void loop() {
  serial.update();
  dataTimer.update();
  antenna.update();
  // delay(3000);
  // antenna.moveTo(pi/6);
  // delay(3000);
  // antenna.moveTo(0);
}

MotorData getMotorData(StepperMotor& motor) {
  return {
    is_moving: motor.isMoving() ? BoolState::BoolState_YES : BoolState::BoolState_NO,
    is_limit_switch_pressed: motor.limitSwitch.isPressed() ? BoolState::BoolState_YES : BoolState::BoolState_NO,
    current_step: motor.currentSteps(),
    target_step: motor.targetSteps(),
    current_angle: (float)motor.currentPosition(),
    target_angle: (float)motor.targetPosition()
  };
}

void sendData() {
  AntennaFirmwareData data = AntennaFirmwareData_init_zero;
  data.has_swivel = true;
  data.swivel = getMotorData(antenna);

  data.has_version = true;
  data.version = version;

  serial.send(&data);
}

void handleCommand(const uint8_t* buffer, int length) {
  auto command = BurtProto::decode<AntennaFirmwareCommand>(buffer, length, AntennaFirmwareCommand_fields);

  // Debug: Move by Individual Steps
  if (command.swivel.move_steps != 0) antenna.moveBySteps(command.swivel.move_steps);

  // Precise Control: Move by # of Rad
  if (command.swivel.move_radians != 0) antenna.moveBy(command.swivel.move_radians);

  // IK Control: Move to Angle (Rad)
  if (command.swivel.angle != 0) antenna.moveTo(command.swivel.angle);
}

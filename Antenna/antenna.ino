#include "src/utils/BURT_utils.h"
#include "src/base_station.pb.h"
#include "pinouts.h"

#define DATA_SEND_INTERVAL 250 // ms

Version version = {major: 1, minor: 0};

void handleCommand(const uint8_t* data, int length);
void sendData();

BurtSerial serial(Device::Device_ANTENNA, handleCommand, BaseStationData_fields, BaseStationData_size);
BurtTimer dataTimer(DATA_SEND_INTERVAL, sendData);

void setup() {
    Serial.begin(9600);
    Serial.println("Initializing MARS subsystem");
    Serial.println("Initializing software...");
    serial.setup();
    dataTimer.setup();

    Serial.println("Initializing hardware...");
    
    Serial.println("Preparing motors...");
    swivel.preSetup();
    pitch.preSetup();
    
    Serial.println("Initializing motors...");
    swivel.setup();
    pitch.setup();

    Serial.println("Calibrating all motors...");
    calibrateAllMotors();
    
    Serial.println("MARS subsystem initialized");
}

void loop() {
    serial.update();
    dataTimer.update();

    swivel.update();
    pitch.update();
}


void stopAllMotors() {
    swivel.stop();
    pitch.stop();
}

void calibrateAllMotors() {
    swivel.calibrate();
    pitch.calibrate();
}

// fix this for antenna- get the correct protobuf messages
MotorData getMotorData(StepperMotor& motor) {
  return {
    is_moving: motor.isMoving() ? BoolState::BoolState_YES : BoolState::BoolState_NO,
    is_limit_switch_pressed: motor.limitSwitch.isPressed() ? BoolState::BoolState_YES : BoolState::BoolState_NO,    // need to update since step-dir-mode removes limit switch
    direction:  0,  // direction field in MotorData protobuf message isn't updated, so this is just set to 0
    current_step: motor.currentSteps(),
    target_step: motor.targetSteps(),
    angle: (float)motor.currentPosition(),
  };
}

void handleCommand(const uint8_t* data, int length) {
    auto command = BurtProto::decode<AntennaCommand>(data, length, AntennaCommand_fields);

    if (command.stop) stopAllMotors();
    if (command.calibrate) calibrateAllMotors();

    if (command.swivel.move_radians != 0) swivel.moveBy(command.swivel.move_radians);
    if (command.pitch.move_radians != 0) pitch.moveBy(command.pitch.move_radians);

}

void sendData() {
    AntennaData data = AntennaData_init_zero;

    data.version = version;
    data.has_version = true;

    data.swivel = getMotorData(swivel);
    data.has_swivel = true;

    data.pitch = getMotorData(pitch);
    data.has_pitch = true;

    serial.send(&data);
}

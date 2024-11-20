#include "src/utils/BURT_utils.h"
#include "src/mars.pb.h"

// TODO: Add AntennaCommand, AntennaData, and Device.ANTENNA to burt_network
// TODO: Add BurtSerial to communicate with the Dashboard

#define DATA_SEND_INTERVAL 250 // ms

BurtSerial serial(Device::Device_ANTENNA, handleCommand, AntennaData_fields, AntennaData_size);
BurtTimer dataTimer(DATA_SEND_INTERVAL, sendData);

void setup() {
    Serial.begin(9600);
    Serial.println("Initializing MARS subsystem");
    Serial.println("Initializing software...");
    serial.setup();
    dataTimer.setup();

    Serial.println("Initializing hardware...");
    /*antenna.setup();*/

    Serial.println("MARS subsystem initialized");
}

void loop() {
    serial.update();
    dataTimer.update();
    /*antenna.update();*/
}

void handleCommand(const uint8_t* data, int length) {
    auto command = BurtProto::decode<AntennaCommand>(data, length, AntennaCommand_fields);
    /*antenna.handleCommand();*/
}

void sendData() {
    serial.send(/*&antenna.data*/)
}

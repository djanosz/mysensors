/**
 * @file gateway.ino
 * @author Grzegorz Krajewski
 *
 * Implementation of the MySensors Gateway.
 *
 * @license GPL V2
 */

// Enable serial gateway
#define MY_GATEWAY_SERIAL

// Define a lower baud rate for Arduino's running on 8 MHz (Arduino Pro Mini 3.3V & SenseBender)
#if F_CPU == 16000000L
#define MY_BAUD_RATE 115200
#endif

// Remember to add library to Arduino path
#include <MySensors.h>
#include "./Mapping/Mapping.hpp"
#include "./Automation/Automation.hpp"

void before() {
  for(uint8_t i = 0; i < maxSensors; i++) {
    pinMode(Sensors[i].id, OUTPUT);
    msgs[i] = MyMessage(Sensors[i].id, V_LIGHT);
    uint8_t currentState = loadState(Sensors[i].id);

    // Check whether EEPROM cell was used before
    if (!(currentState == 0|1)) {
      currentState = Relay::OFF;
      saveState(Sensors[i].id, currentState);
    }

    setGPIO(Sensors[i].pin, currentState);
  }
}

void setup() {
  setupButtons();
}

void presentation()
{
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo("Gateway", "1.5");

  // Send actual states
  for (uint8_t i = 0; i < maxSensors; i++) {
    const uint8_t id = Sensors[i].id;
    present(id, S_BINARY, Sensors[i].description);
    send(msgs[i].set(loadState(id)));
  }
}

void loop() {
  // Keep sensing buttons
  saloon.tick();
  gamingRoom.tick();
  bedroom.tick();
  bed1.tick();
  bed2.tick();
  guests.tick();
  bathroom.tick();
  mirror.tick();
  kitchen.tick();
  kitchenTable.tick();
  workshop.tick();
  corridor.tick();
}

void receive(const MyMessage &message) {
  // We only expect one type of message from controller. But we better check anyway.
  if (message.type==V_STATUS) {

    uint8_t Id = getId(message.sensor);
    const bool value = message.getBool();
    // Store state in eeprom and send message
    setOutput(Sensors[Id].id, value);
  }
}

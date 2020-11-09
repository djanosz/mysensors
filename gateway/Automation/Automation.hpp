/**
 * @file Automation.hpp
 * @author Grzegorz Krajewski
 *
 * Automation for buttons & sensors.
 *
 * @license GPL V2
 */

#pragma once

#include "../Mapping/Mapping.hpp"

void setOutput(const uint8_t& sensorId, const uint8_t& cmd = Relay::FLIP) {
  // test whether sensor with given ID exists and get it's index in container
  // TODO: Add debug message when idx is wrong & in any other places where: Sensors[idx]
  uint8_t idx = getIdx(sensorId);
  auto sensor = Sensors[idx];

  // check whether flip state of sensor
  const uint8_t state = (cmd == Relay::FLIP) ? !loadState(sensor.id) : cmd;
  saveState(sensor.id, state);

  // inverse state if sensors is Active Low
  bool bState = static_cast<bool>(state);
  bState = (ActiveLow == sensor.activelow) ? !bState : bState;

  digitalWrite(sensor.pin, bState);
  send(msgs[idx].set(state));
}

void clickCallback(void* pSensorId) {
  // TODO: Test whether this can be null or nullptr or unexpected value
  const uint8_t sensorId = static_cast<uint8_t>(reinterpret_cast<intptr_t>(pSensorId));
  setOutput(sensorId);
}

void saloonClick() {
  setOutput(KORYTARZ_5_ID);
}
void saloonDoubleClick() {
  setOutput(KORYTARZ_1_ID);
}
void saloonOff() {
  setOutput(SALOON_3_ID);
}
void saloon3Click() {
  setOutput(SALOON_2_ID);
  //setOutput(SALOON_2_ID);
}
void saloon3DoubleClick() {
  // placeholder
}
void saloon3Off() {
  //setOutput(SALOON_1_ID, Relay::OFF);
  //setOutput(SALOON_2_ID, Relay::OFF);
}
void sypialniaClick() {
  setOutput(SYPIALNIA_ID);
  //setOutput(SALOON_2_ID);
}
void sypialniaDoubleClick() {
  setOutput(KORYTARZ_1_ID);
}
void sypialniaOff() {
  //setOutput(SALOON_1_ID, Relay::OFF);
  //setOutput(SALOON_2_ID, Relay::OFF);
}
void sypialnia2Click() {
  setOutput(SYPIALNIA2_ID);
  //setOutput(SALOON_2_ID);
}
void sypialnia2DoubleClick() {
  setOutput(KORYTARZ_1_ID);
}
void sypialnia2Off() {
  //setOutput(SALOON_1_ID, Relay::OFF);
  //setOutput(SALOON_2_ID, Relay::OFF);
}
void garderobaClick() {
  setOutput(GARDEROBA_ID);
}
void garderobaDoubleClick() {
  setOutput(KORYTARZ_5_ID);
}
void garderobaOff() {
  setOutput(GARDEROBA_2_ID);
}
void hania1Click() {
  setOutput(HANIA_1_ID);
}
void hania1DoubleClick() {
  // placeholder
}
void hania1Off() {
  // placeholder
}
void hania2Click() {
  setOutput(HANIA_2_ID);
}
void hania2DoubleClick() {
  // placeholder
}
void hania2Off() {
  // placeholder
}
void korytarz2Click() {
  setOutput(KORYTARZ_1_ID);
}
void korytarz2DoubleClick() {
  setOutput(KORYTARZ_2_ID);
}
void korytarz2Off() {
  setOutput(SALOON_2_ID, Relay::OFF);
  setOutput(KORYTARZ_5_ID, Relay::OFF);
  setOutput(GARDEROBA_ID, Relay::OFF);
  setOutput(KORYTARZ_ID, Relay::OFF);
  setOutput(SYPIALNIA_ID, Relay::OFF);
  setOutput(SYPIALNIA2_ID, Relay::OFF);
  setOutput(HANIA_1_ID, Relay::OFF);
  setOutput(HANIA_2_ID, Relay::OFF);
  setOutput(ALL_OFF_ID, Relay::OFF);
  setOutput(KORYTARZ_1_ID, Relay::OFF);
  setOutput(GARDEROBA_2_ID, Relay::OFF);
}
void korytarzLClick() {
  setOutput(KORYTARZ_3_ID);
}
void korytarzLDoubleClick() {
  // placeholder
}
void korytarzLOff() {
  // placeholder
}
void setupButtons() {
  // Setup the button.
  saloon.attachClick(saloonClick);
  saloon.attachLongPressStop(saloonOff);
  saloon.attachDoubleClick(saloonDoubleClick);
  
  saloon3.attachClick(saloon3Click);
  saloon3.attachLongPressStop(saloon3Off);
  saloon3.attachDoubleClick(saloon3DoubleClick);
  
  sypialnia.attachClick(sypialniaClick);
  sypialnia.attachLongPressStop(sypialniaOff);
  sypialnia.attachDoubleClick(sypialniaDoubleClick);
  
  sypialnia2.attachClick(sypialnia2Click);
  sypialnia2.attachLongPressStop(sypialnia2Off);
  sypialnia2.attachDoubleClick(sypialnia2DoubleClick);
  
  garderoba.attachClick(garderobaClick);
  garderoba.attachLongPressStop(garderobaOff);
  garderoba.attachDoubleClick(garderobaDoubleClick);
  
  hania1.attachClick(hania1Click);
  hania1.attachLongPressStop(hania1Off);
  hania1.attachDoubleClick(hania1DoubleClick);
  
  hania2.attachClick(hania2Click);
  hania2.attachLongPressStop(hania2Off);
  hania2.attachDoubleClick(hania2DoubleClick);
  
  korytarz2.attachClick(korytarz2Click);
  korytarz2.attachLongPressStop(korytarz2Off);
  korytarz2.attachDoubleClick(korytarz2DoubleClick);
  
  korytarzL.attachClick(korytarzLClick);
  korytarzL.attachLongPressStop(korytarzLOff);
  korytarzL.attachDoubleClick(korytarzLDoubleClick);
}

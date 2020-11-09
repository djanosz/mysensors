/**
 * @file Mapping.hpp
 * @author Grzegorz Krajewski
 *
 * Mappings.
 *
 * @license GPL V2
 */

#pragma once

#include <OneButton.h>

namespace Relay {
  const uint8_t OFF  = 0;
  const uint8_t ON   = 1;
  const uint8_t FLIP = 2;
}
const bool ActiveLow = true;

// Child ID declaration of relays
const uint8_t GARDEROBA_2_ID    = 1; //Garderoba wentylator
const uint8_t SALOON_2_ID        = 2; // Salon Lampa
const uint8_t SALOON_3_ID        = 3; // Salon Projektor
const uint8_t GARDEROBA_ID        = 4; // Garderoba
const uint8_t KORYTARZ_ID        = 5; // Korytarz podświetlenie podłgi
const uint8_t SYPIALNIA_ID        = 6; // Sypialnia lampa
const uint8_t SYPIALNIA2_ID        = 7; // Sypialnia wirtualny
const uint8_t HANIA_1_ID        = 8; // Pokój Hani Lampa 1/2
const uint8_t HANIA_2_ID        = 9; // Pokój Hani Lampa 2/2
const uint8_t KORYTARZ_1_ID        = 10;// Korytarz Lampa główna
const uint8_t ALL_OFF_ID        = 12; // Wirtualny OFF wszusytko
const uint8_t KORYTARZ_2_ID        = 13; // Wirtualny gniazdo żelazko
const uint8_t KORYTARZ_3_ID        = 14; // Wirtualny odblokowywanie drzwi zielone
const uint8_t KORYTARZ_4_ID        = 15; // odblokowywanie drzwi zielone
const uint8_t KORYTARZ_5_ID        = 16; // Korytarz lapmpa dodatkowa

typedef struct {
  const uint8_t id;
  const char* description;
  const uint8_t pin;
  bool activelow;
} SensorsStruct;

SensorsStruct Sensors [] = {
//  Child ID           description       pin activelow
  { GARDEROBA_2_ID,      "Garderoba wentylator",    11, true }, //11
  { SALOON_2_ID,         "Salon Lampa",              4, true },
  { SALOON_3_ID,         "Salon Projektor",          6, true },
  { GARDEROBA_ID,        "Garderoba",                8, true },
  { KORYTARZ_ID,         "Podświetlenie podłogi",   38, true },
  { SYPIALNIA_ID,        "Sypialnia Lampa",         10, true },
  { SYPIALNIA2_ID,       "Sypialnia Wirtual",       -1, true },
  { HANIA_1_ID,          "Lampa 1/2 pokój Hani",     7, true },
  { HANIA_2_ID,          "Lampa 2/2 pokój Hani",     7, true }, //docelowo inny pin 2 zestaw ssr
  { KORYTARZ_1_ID,       "Korytarz lampa główna",    9, true },
  { ALL_OFF_ID,          "Wyłącz wszystko",         -3, true },
  { KORYTARZ_2_ID,       "Gniazdko korytarz",       -4, true },
  { KORYTARZ_3_ID,       "Drzwi wirtualny",         -5, false }, //włącznik wirtualny
  { KORYTARZ_4_ID,       "Odblokowanie drzwi",      24, false }, //przekaźnik
  { KORYTARZ_5_ID,       "Korytarz Lampa 2",        30, false }, //przekaźnik
};
const uint8_t maxSensors = sizeof(Sensors) / sizeof(SensorsStruct);
MyMessage msgs[maxSensors];

uint8_t getIdx(uint8_t sensorId) {
  for (uint8_t i = 0; i < maxSensors; i++) {
    if (Sensors[i].id == sensorId) return(i);
  }
  return(-1);
}

// Pushbuttons declaration
// Remember that names should be consistent with main loop in gateway.ino
OneButton saloon(A1, true); // Włącznik salon lewy
OneButton saloon3(A8, true);  // Włącznik salon prawy
OneButton sypialnia(A7, true);  // Włącznik sypialnia prawy
OneButton sypialnia2(A9, true);  // Włącznik sypialnia lewy
OneButton garderoba(A10, true);  // Włącznik garderoba
OneButton hania1(A11, true);  // Włącznik pokój Hani lewy
OneButton hania2(A12, true);  // Włącznik pokój Hani prawy
OneButton korytarz2(A13, true);  // Wxłącznik korytarz prawy
OneButton korytarzL(A14, true);  // Włącznik korytarz Lewy

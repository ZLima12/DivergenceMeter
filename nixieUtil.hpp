#pragma once

#include <stdint.h>

// Math Stuff
uint64_t powerOfTen(uint8_t power);
uint8_t baseTenLength(uint64_t num);

// General Formatting
uint8_t* splitNum(uint64_t num, uint8_t desiredLength);

// Nixie Formatting
uint8_t nixiePairFormat(uint8_t l, uint8_t r);
uint8_t* meterFormat(uint32_t num);


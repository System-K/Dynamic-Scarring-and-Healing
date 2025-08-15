#pragma once

#include <random>

// Declare extern generator
extern std::mt19937 gen;

// (Optional) Declare commonly used distributions
extern std::uniform_real_distribution<float> dist01;   // 0.0 to 1.0
extern std::uniform_real_distribution<float> dist100;  // 0.0 to 100.0

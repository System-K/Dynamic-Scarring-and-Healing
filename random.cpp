#include "random.h"

std::random_device rd;
std::mt19937 gen(rd());

// Define any distributions
std::uniform_real_distribution<float> dist01(0.0f, 1.0f);
std::uniform_real_distribution<float> dist100(0.0f, 100.0f);

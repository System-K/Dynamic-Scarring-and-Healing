#include "mcm.h"

float healthThreshold = 20.0f;
float scarChance = 100.0f;
int maxScarCount = 5;

void LoadMCMSettings() {
    std::ifstream iniFile("Data\\MCM\\Settings\\Dynamic Scarring and Healing.ini");
    if (!iniFile.is_open()) {
        spdlog::warn("Could not open Dynamic Scarring and Healing.ini");
        return;
    }

    std::string line;
    while (std::getline(iniFile, line)) {
        if (line.rfind("iHealthThreshold", 0) == 0) {
            size_t equalsPos = line.find('=');
            if (equalsPos != std::string::npos) {
                try {
                    healthThreshold = std::stof(line.substr(equalsPos + 1));
                    spdlog::info("Loaded iHealthThreshold = {}", healthThreshold);
                } catch (...) {
                    spdlog::warn("Failed to parse iHealthThreshold");
                }
            }
        }
        if (line.rfind("iScarChance", 0) == 0) {
            size_t equalsPos = line.find('=');
            if (equalsPos != std::string::npos) {
                try {
                    scarChance = std::stof(line.substr(equalsPos + 1));
                    spdlog::info("Loaded iScarChance = {}", scarChance);
                } catch (...) {
                    spdlog::warn("Failed to parse iScarChance");
                }
            }
        }
        if (line.rfind("iMaxScarCount", 0) == 0) {
            size_t equalsPos = line.find('=');
            if (equalsPos != std::string::npos) {
                try {
                    maxScarCount = std::stof(line.substr(equalsPos + 1));
                    spdlog::info("Loaded iMaxScarCount = {}", maxScarCount);
                } catch (...) {
                    spdlog::warn("Failed to parse iMaxScarCount");
                }
            }
        }
    }
}
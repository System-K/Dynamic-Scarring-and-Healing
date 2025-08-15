#pragma once

#include <optional>
#include <string>
#include <vector>

extern std::mt19937 gen;

// These should be declared extern so they're shared across translation units
extern std::vector<std::string> ImperfectSkinOverlay_Paths;
extern std::vector<std::string> SkinFeatureOverlay_Paths;
extern std::vector<std::string> WoundsOverlay_Paths;

// Flags that indicate plugin installation
extern bool ImperfectSkinOverlay_Installed;
extern bool SkinFeatureOverlay_Installed;
extern bool WoundsOverlay_Installed;

// Random texture selector
std::optional<std::string> GetRandomOverlayTexturePath();
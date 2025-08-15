#pragma once
#include <string_view>

extern bool WoundsOverlay_Installed;
extern bool SkinFeatureOverlay_Installed;
extern bool ImperfectSkinOverlay_Installed;

bool IsPluginInstalled(std::string_view pluginName);
void checkForInstalledPlugins();

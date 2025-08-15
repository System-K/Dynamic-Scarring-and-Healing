#include "PluginDetection.h"
#include <spdlog/spdlog.h>

// Define the global variables declared in the header
bool WoundsOverlay_Installed = false;
bool SkinFeatureOverlay_Installed = false;
bool ImperfectSkinOverlay_Installed = false;

bool IsPluginInstalled(std::string_view pluginName) {
    auto* dataHandler = RE::TESDataHandler::GetSingleton();
    if (!dataHandler) return false;

    if (auto* mod = dataHandler->LookupLoadedModByName(pluginName.data())) return true;

    for (const auto& file : dataHandler->files) {
        if (file && file->IsLight() && _stricmp(file->fileName, pluginName.data()) == 0) {
            return true;
        }
    }

    return false;
}

void checkForInstalledPlugins() {
    if (IsPluginInstalled("WoundsOverlay.esp")) {
        spdlog::info("WoundsOverlay.esp is installed.");
        WoundsOverlay_Installed = true;
    } else {
        spdlog::warn("WoundsOverlay.esp is NOT installed or NOT loaded.");
    }
    if (IsPluginInstalled("SFO_SkinFeatureOverlays.esp")) {
        spdlog::info("SFO_SkinFeatureOverlays.esp is installed.");
        SkinFeatureOverlay_Installed = true;
    } else {
        spdlog::warn("SFO_SkinFeatureOverlays.esp is NOT installed or NOT loaded.");
    }
    if (IsPluginInstalled("ImperfectOverlays.esp")) {
        spdlog::info("ImperfectOverlays.esp is installed.");
        ImperfectSkinOverlay_Installed = true;
    } else {
        spdlog::warn("ImperfectOverlays.esp is NOT installed or NOT loaded.");
    }
}
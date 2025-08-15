#include "Logger.h"
#include <spdlog/sinks/basic_file_sink.h>
#include "SKSE/SKSE.h"

namespace Logger {

    void Init() {
        auto logsFolder = SKSE::log::log_directory();

        if (logsFolder && logsFolder->string().find("Skyrim.INI") != std::string::npos) {
            const char* userProfile = std::getenv("USERPROFILE");
            if (!userProfile) {
                SKSE::stl::report_and_fail("USERPROFILE not set; cannot resolve fallback log path.");
            }

            logsFolder =
                std::filesystem::path(userProfile) / "Documents" / "My Games" / "Skyrim Special Edition" / "SKSE";
            std::filesystem::create_directories(*logsFolder);
        }

        if (!logsFolder) {
            SKSE::stl::report_and_fail("SKSE log_directory not provided, logs disabled.");
        }

        auto pluginName = SKSE::PluginDeclaration::GetSingleton()->GetName();
        auto logFilePath = *logsFolder / std::format("{}.log", pluginName);

        auto fileLoggerPtr = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logFilePath.string(), true);
        auto loggerPtr = std::make_shared<spdlog::logger>("log", std::move(fileLoggerPtr));
        spdlog::set_default_logger(std::move(loggerPtr));
        spdlog::set_level(spdlog::level::trace);
        spdlog::flush_on(spdlog::level::trace);

        spdlog::info("Logger initialized at: {}", logFilePath.string());
    }

}

#include <spdlog/sinks/basic_file_sink.h>
#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"
#include "RE/V/VirtualMachine.h"
#include "random.h"
#include "pluginDetection.h"
#include "overlays.h"
#include "mcm.h"
#include "logger.h"


namespace logger = SKSE::log;

void CallPapyrusLowHealthHandler() {
    auto* vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
    if (!vm) {
        return;
    }

    RE::TESForm* form = RE::TESForm::LookupByEditorID("DynamicScarsQuest");  
    if (!form) {
        return;
    }

    auto policy = vm->GetObjectHandlePolicy();
    RE::VMHandle handle = policy->GetHandleForObject(form->GetFormType(), form);
    if (handle == policy->EmptyHandle()) {
        return;
    }

    RE::BSFixedString scriptName("ScarOverlayHandler");
    RE::BSFixedString functionName("ApplyScarOverlay");

    RE::BSTSmartPointer<RE::BSScript::Object> object;
    RE::BSTSmartPointer<RE::BSScript::IStackCallbackFunctor> result;

    if (!vm->FindBoundObject(handle, scriptName.c_str(), object)) {
        logger::error("Could not find bound object for script '{}'", scriptName.c_str());
        return;
    }

    auto randomOverlayPath = GetRandomOverlayTexturePath();
    if (!randomOverlayPath) {
        logger::warn("No overlay textures available to apply");
        return;
    }

    RE::BSFixedString overlayPath(randomOverlayPath->c_str());
    int colorVal = 0xeb0905;
    float alpha = 1.0f;

    auto args = RE::MakeFunctionArguments(std::move(overlayPath),std::move(maxScarCount),std::move(colorVal),std::move(alpha));

    logger::info("sending path {}", randomOverlayPath.value());

    vm->DispatchMethodCall1(object, functionName, args, result);
}

class EventProcessor : public RE::BSTEventSink<RE::TESHitEvent> {
public:
    static EventProcessor& GetSingleton() {
        static EventProcessor instance;
        return instance;
    }

RE::BSEventNotifyControl ProcessEvent(const RE::TESHitEvent* event, RE::BSTEventSource<RE::TESHitEvent>*) override {
        if (!event) {
            logger::info("TESHitEvent was null");
            return RE::BSEventNotifyControl::kContinue;
        }

        auto target = event->target.get();
        if (!target || !target->IsPlayerRef()) {
            logger::info("TESHitEvent: target is not the player");
            return RE::BSEventNotifyControl::kContinue;
        }

        auto player = RE::PlayerCharacter::GetSingleton();
        if (!player) {
            logger::info("No player singleton in event handler");
            return RE::BSEventNotifyControl::kContinue;
        }

        float currentHealth = player->AsActorValueOwner()->GetActorValue(RE::ActorValue::kHealth);
        float maxHealth = player->AsActorValueOwner()->GetPermanentActorValue(RE::ActorValue::kHealth);


        float healthPercent = (currentHealth / maxHealth) * 100.0f;
        if (healthPercent > healthThreshold) {
            return RE::BSEventNotifyControl::kContinue;
        }

        //Scar Chance Logic
        float roll = dist100(gen);
        if (roll > scarChance) {
            return RE::BSEventNotifyControl::kContinue;
        }

        const char* causeName = event->cause.get() ? event->cause.get()->GetName() : "unknown";
        logger::info("Sending mod event: ApplyScarOverlay");

        CallPapyrusLowHealthHandler();

        return RE::BSEventNotifyControl::kContinue;
    }
};

void UpdateSettings(RE::StaticFunctionTag*) {
    LoadMCMSettings();
}

bool PapyrusFunctions(RE::BSScript::IVirtualMachine* a_vm) {
    a_vm->RegisterFunction("UpdateSettings", "DynamicScarsStub", UpdateSettings);
    return true;
}


SKSEPluginLoad(const SKSE::LoadInterface* skse) {
    SKSE::Init(skse);
    Logger::Init();

    //On Game Load
    SKSE::GetMessagingInterface()->RegisterListener([](SKSE::MessagingInterface::Message* msg) {
        if (msg->type == SKSE::MessagingInterface::kDataLoaded) {
            checkForInstalledPlugins();
            LoadMCMSettings();
        }
    });

    logger::info("Plugin loaded successfully");

    //Subscribe to Hit Events
    auto& eventProcessor = EventProcessor::GetSingleton();
    RE::ScriptEventSourceHolder::GetSingleton()->AddEventSink<RE::TESHitEvent>(&eventProcessor);
    logger::info("Subscribed to TESHitEvent");

    //Subscribe to PapyrusFunction
    if (!SKSE::GetPapyrusInterface()->Register(PapyrusFunctions)) {
        logger::error("Failed to register Papyrus functions!");
    } else {
        logger::info("Successfully registered Papyrus functions.");
    }

    return true;
}




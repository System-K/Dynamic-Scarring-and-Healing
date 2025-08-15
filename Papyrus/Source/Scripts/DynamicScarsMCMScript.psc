Scriptname DynamicScarsMCMScript extends MCM_ConfigBase

; Call this to notify SKSE plugin directly
Function UpdateSettings()
    Debug.Trace("Calling SKSE UpdateSettings")
    DynamicScarsStub.UpdateSettings()
EndFunction

Event OnSettingChange(string a_ID)
    Debug.Trace("Setting changed: " + a_ID)
    UpdateSettings()
EndEvent
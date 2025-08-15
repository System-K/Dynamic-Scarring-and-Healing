Scriptname DynamicScarsFadingScript extends Quest  

import NiOverride
import MCM

Actor property PlayerRef auto
bool property IsFemale auto
string property Area = "Body" auto
float property FadeRate = 0.01 auto  ; how much alpha reduces each hour

float LastUpdateHour = -1.0


Event OnInit()
    PlayerRef = Game.GetPlayer()
    IsFemale = PlayerRef.GetLeveledActorBase().GetSex() == 1
    LastUpdateHour = Utility.GetCurrentGameTime() * 24.0
    RegisterForSingleUpdateGameTime(1.0)
EndEvent

Event OnUpdateGameTime()

    float nowHour = Utility.GetCurrentGameTime() * 24.0
    float hoursPassed = nowHour - LastUpdateHour
    LastUpdateHour = nowHour

    if hoursPassed < 0
        hoursPassed = 0 ; safety
    endif

    int loops = Math.Floor(hoursPassed)
    if loops < 1
        loops = 1
    endif

    while loops > 0
        FadeScars()
        loops -= 1
    endwhile
    RegisterForSingleUpdateGameTime(1.0)
EndEvent

function FadeScars()
    int i = 0
    int scarLimit = GetModSettingInt("Dynamic Scarring and Healing","iMaxScarCount:Main")
    FadeRate = GetModSettingInt("Dynamic Scarring and Healing","iScarFadeRate:Main") * 0.01
    Debug.Trace("Got Scar Limit"+scarLimit)
    while (i <= scarLimit)
        string node = Area + " [ovl" + i + "]"
        string path = NiOverride.GetNodeOverrideString(PlayerRef, IsFemale, node, 9, 0)
        if (path != "")
            float alpha = NiOverride.GetNodeOverrideFloat(PlayerRef, IsFemale, node, 8, -1)
            alpha -= FadeRate
            if (alpha <= 0.01)
                ClearOverlay(i)
                Debug.Trace("Cleared scar in slot " + i)
            else
                ; Clamp just in case
                if (alpha < 0.0)
                    alpha = 0.0
                endif
                NiOverride.AddNodeOverrideFloat(PlayerRef, IsFemale, node, 8, -1, alpha, true)
                Debug.Trace("Faded scar in slot " + i + " to alpha " + alpha)
            endif
        else
            Debug.Trace("No texture path for overlay slot " + i)
        endif
        i += 1
    endwhile
endFunction

function ClearOverlay(int slot)
    string node = Area + " [ovl" + slot + "]"

    ; Set alpha to 0 (fade out)
    NiOverride.AddNodeOverrideFloat(PlayerRef, IsFemale, node, 8, -1, 0.0, true)

    ; Then remove all override metadata
    NiOverride.RemoveNodeOverride(PlayerRef, IsFemale, node, 9, 0)  ; texture path
    NiOverride.RemoveNodeOverride(PlayerRef, IsFemale, node, 7, -1) ; color
    NiOverride.RemoveNodeOverride(PlayerRef, IsFemale, node, 0, -1) ; glow color
    NiOverride.RemoveNodeOverride(PlayerRef, IsFemale, node, 1, -1) ; glow alpha
    NiOverride.AddOverlays(PlayerRef)
endFunction
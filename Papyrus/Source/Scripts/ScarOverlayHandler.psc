Scriptname ScarOverlayHandler extends Quest

import NiOverride

function ApplyScarOverlay(string path, int maxSlot, int colorVal, float alphaVal)
	Actor PlayerRef = Game.GetPlayer()
	bool isFemale = PlayerRef.GetLeveledActorBase().GetSex() == 1
	string area = "Body"
	int glowVal = 0
	float glowAlphaVal = 0.0

	int slot = FindEmptyOverlaySlot(PlayerRef, isFemale, area, maxSlot)
	if (slot == -1)
		Debug.Trace("No empty scar slot found.")
		return
	endif

	apply_overlay(PlayerRef, isFemale, area, slot, path, colorVal, alphaVal, glowVal, glowAlphaVal)
	NiOverride.AddOverlays(PlayerRef)

	Debug.Trace("Scar Applied.")
endFunction

int function FindEmptyOverlaySlot(Actor akActor, bool isFemale, string area, int maxSlot)
	int i = 0
      debug.Trace("MaxSlot : Overlay : "+maxSlot)
	while (i <= maxSlot)
		string nodeName = area + " [ovl" + i + "]"

		; Check the current texture path
		string existingPath = NiOverride.GetNodeOverrideString(akActor, isFemale, nodeName, 9, 0)

		; Check the alpha value (opacity)
		float existingAlpha = NiOverride.GetNodeOverrideFloat(akActor, isFemale, nodeName, 8, -1)

		; Consider the slot empty if either:
		; 1. No path has been applied
		; 2. Path exists, but it's invisible (alpha == 0)
		if (existingPath == "" || existingAlpha <= 0.001)
			return i
		endif

		i += 1
	endwhile
	return -1 ; No empty slot found
endFunction

bool function apply_overlay(Actor target, bool isFemale, string area, int slot, string path, int colorVal, float alphaVal, int glowVal, float glowAlphaVal) global
	glowAlphaVal *= 25.5
	string nodeName = area + " [ovl" + slot + "]"

	NiOverride.AddNodeOverrideString(target, isFemale, nodeName, 9, 0, path, true)
	Utility.Wait(0.01)
	NiOverride.AddNodeOverrideInt(target, isFemale, nodeName, 7, -1, colorVal, true)
	Utility.Wait(0.01)
	NiOverride.AddNodeOverrideFloat(target, isFemale, nodeName, 8, -1, alphaVal, true)
	Utility.Wait(0.01)
	NiOverride.AddNodeOverrideInt(target, isFemale, nodeName, 0, -1, glowVal, true)
	Utility.Wait(0.01)
	NiOverride.AddNodeOverrideFloat(target, isFemale, nodeName, 1, -1, glowAlphaVal, true)

	return true
endFunction

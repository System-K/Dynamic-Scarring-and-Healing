#include "overlays.h"
#include "random.h"

std::vector<std::string> ImperfectSkinOverlay_Paths = {
    "textures\\actors\\character\\overlays\\iso\\isodarml01.dds",
    "textures\\actors\\character\\overlays\\iso\\isodarml02.dds",
    "textures\\actors\\character\\overlays\\iso\\isodarml03.dds",
    "textures\\actors\\character\\overlays\\iso\\isodarml04.dds",

    "textures\\actors\\character\\overlays\\iso\\isodarmr01.dds",
    "textures\\actors\\character\\overlays\\iso\\isodarmr02.dds",
    "textures\\actors\\character\\overlays\\iso\\isodarmr03.dds",
    "textures\\actors\\character\\overlays\\iso\\isodarmr04.dds",

    "textures\\actors\\character\\overlays\\iso\\isodback01.dds",
    "textures\\actors\\character\\overlays\\iso\\isodback02.dds",
    "textures\\actors\\character\\overlays\\iso\\isodback03.dds",
    "textures\\actors\\character\\overlays\\iso\\isodback04.dds",

    "textures\\actors\\character\\overlays\\iso\\isodbelly01.dds",
    "textures\\actors\\character\\overlays\\iso\\isodbelly02.dds",
    "textures\\actors\\character\\overlays\\iso\\isodbelly03.dds",
    "textures\\actors\\character\\overlays\\iso\\isodbelly04.dds",
    "textures\\actors\\character\\overlays\\iso\\isodbelly05.dds",

    "textures\\actors\\character\\overlays\\iso\\isodbutt01.dds",
    "textures\\actors\\character\\overlays\\iso\\isodbutt02.dds",

    "textures\\actors\\character\\overlays\\iso\\isodfull01.dds",
    "textures\\actors\\character\\overlays\\iso\\isodfull02.dds",

    "textures\\actors\\character\\overlays\\iso\\isodlegl01.dds",
    "textures\\actors\\character\\overlays\\iso\\isodlegl02.dds",
    "textures\\actors\\character\\overlays\\iso\\isodlegl03.dds",
    "textures\\actors\\character\\overlays\\iso\\isodlegl04.dds",
    "textures\\actors\\character\\overlays\\iso\\isodlegl05.dds",

    "textures\\actors\\character\\overlays\\iso\\isodlegr01.dds",
    "textures\\actors\\character\\overlays\\iso\\isodlegr02.dds",
    "textures\\actors\\character\\overlays\\iso\\isodlegr03.dds",
    "textures\\actors\\character\\overlays\\iso\\isodlegr04.dds",
    "textures\\actors\\character\\overlays\\iso\\isodlegr05.dds",

    "textures\\actors\\character\\overlays\\iso\\isodshoulderl01.dds",
    "textures\\actors\\character\\overlays\\iso\\isodshoulderl02.dds",
    "textures\\actors\\character\\overlays\\iso\\isodshoulderl03.dds",
    "textures\\actors\\character\\overlays\\iso\\isodshoulderl04.dds",

    "textures\\actors\\character\\overlays\\iso\\isodshoulderr01.dds",
    "textures\\actors\\character\\overlays\\iso\\isodshoulderr02.dds",
    "textures\\actors\\character\\overlays\\iso\\isodshoulderr03.dds",
    "textures\\actors\\character\\overlays\\iso\\isodshoulderr04.dds",

    "textures\\actors\\character\\overlays\\iso\\isodtorso02.dds",
    "textures\\actors\\character\\overlays\\iso\\isodtorso01.dds",

    "textures\\actors\\character\\overlays\\iso\\isolarml01.dds",
    "textures\\actors\\character\\overlays\\iso\\isolarml02.dds",
    "textures\\actors\\character\\overlays\\iso\\isolarml03.dds",
    "textures\\actors\\character\\overlays\\iso\\isolarml04.dds",
                                                    
    "textures\\actors\\character\\overlays\\iso\\isolarmr01.dds",
    "textures\\actors\\character\\overlays\\iso\\isolarmr02.dds",
    "textures\\actors\\character\\overlays\\iso\\isolarmr03.dds",
    "textures\\actors\\character\\overlays\\iso\\isolarmr04.dds",

    "textures\\actors\\character\\overlays\\iso\\isolback01.dds",
    "textures\\actors\\character\\overlays\\iso\\isolback02.dds",
    "textures\\actors\\character\\overlays\\iso\\isolback03.dds",
    "textures\\actors\\character\\overlays\\iso\\isolback04.dds",
                                                    
    "textures\\actors\\character\\overlays\\iso\\isolbelly01.dds",
    "textures\\actors\\character\\overlays\\iso\\isolbelly02.dds",
    "textures\\actors\\character\\overlays\\iso\\isolbelly03.dds",
    "textures\\actors\\character\\overlays\\iso\\isolbelly04.dds",
    "textures\\actors\\character\\overlays\\iso\\isolbelly05.dds",

    "textures\\actors\\character\\overlays\\iso\\isolbutt01.dds",
    "textures\\actors\\character\\overlays\\iso\\isolbutt02.dds",

    "textures\\actors\\character\\overlays\\iso\\isolfull01.dds",
    "textures\\actors\\character\\overlays\\iso\\isolfull02.dds",

    "textures\\actors\\character\\overlays\\iso\\isollegl01.dds",
    "textures\\actors\\character\\overlays\\iso\\isollegl02.dds",
    "textures\\actors\\character\\overlays\\iso\\isollegl03.dds",
    "textures\\actors\\character\\overlays\\iso\\isollegl04.dds",
    "textures\\actors\\character\\overlays\\iso\\isollegl05.dds",
                                                    
    "textures\\actors\\character\\overlays\\iso\\isollegr01.dds",
    "textures\\actors\\character\\overlays\\iso\\isollegr02.dds",
    "textures\\actors\\character\\overlays\\iso\\isollegr03.dds",
    "textures\\actors\\character\\overlays\\iso\\isollegr04.dds",
    "textures\\actors\\character\\overlays\\iso\\isollegr05.dds",

    "textures\\actors\\character\\overlays\\iso\\isolshoulderl01.dds",
    "textures\\actors\\character\\overlays\\iso\\isolshoulderl02.dds",
    "textures\\actors\\character\\overlays\\iso\\isolshoulderl03.dds",
    "textures\\actors\\character\\overlays\\iso\\isolshoulderl04.dds",
                                                    
    "textures\\actors\\character\\overlays\\iso\\isolshoulderr01.dds",
    "textures\\actors\\character\\overlays\\iso\\isolshoulderr02.dds",
    "textures\\actors\\character\\overlays\\iso\\isolshoulderr03.dds",
    "textures\\actors\\character\\overlays\\iso\\isolshoulderr04.dds",
                                                    
    "textures\\actors\\character\\overlays\\iso\\isoltorso02.dds",
    "textures\\actors\\character\\overlays\\iso\\isoltorso01.dds",
};

std::vector<std::string> SkinFeatureOverlay_Paths = {
    "textures\\actors\\character\\overlays\\sfo\\Scars Arm Gnashes.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Back Scratches.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Back Slashes 1.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Back Slashes 2.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Back Slashes 3.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Back Slashes 4.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Birth.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Breast.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Burn Back.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Burn Belly 1.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Burn Leg 2.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Burn Leg.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Burn Shoulder 2.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Burn Shoulder.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Chest Gnashes.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Chest Marks.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Clawed Back.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Engraved Count.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Flagellation Arm 1.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Flagellation Back 1.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Flagellation Back 2.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Flagellation Chest 1.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Front Slashes 1.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Front Slashes 2.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Front Slashes 3.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Front Slashes 4.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Full Body 1.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Full Body 2.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Left Leg Gnash.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Leg Slashes.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Right Leg Gnash.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Slashed Arm.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Slashed Shoulder.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Stomach Gnash.dds",
    "textures\\actors\\character\\overlays\\sfo\\Scars Vertical Torso.dds",
};

std::vector<std::string> WoundsOverlay_Paths = {
    "textures\\actors\\character\\character assets\\overlays\\Wounds_Arm_Left_Bruise.dds",
    "textures\\actors\\character\\character assets\\overlays\\Wounds_Arm_Left_Long.dds",
    "textures\\actors\\character\\character assets\\overlays\\Wounds_Arm_Left_Small.dds",
    "textures\\actors\\character\\character assets\\overlays\\Wounds_Arm_Right.dds",
    "textures\\actors\\character\\character assets\\overlays\\Wounds_Back_Long.dds",
    "textures\\actors\\character\\character assets\\overlays\\Wounds_Chest.dds",
    "textures\\actors\\character\\character assets\\overlays\\Wounds_Legs_Left.dds",
    "textures\\actors\\character\\character assets\\overlays\\Wounds_Legs_Left_Bruises.dds",
    "textures\\actors\\character\\character assets\\overlays\\Wounds_Legs_Right.dds",
    "textures\\actors\\character\\character assets\\overlays\\Wounds_Legs_Right_Bruises.dds",
    "textures\\actors\\character\\character assets\\overlays\\Wounds_Smaller_Back.dds",
    "textures\\actors\\character\\character assets\\overlays\\Wounds_Torso_Bruises.dds",
};

std::optional<std::string> GetRandomOverlayTexturePath() {
    std::vector<std::string> allAvailable;

    if (ImperfectSkinOverlay_Installed) {
        allAvailable.insert(allAvailable.end(), ImperfectSkinOverlay_Paths.begin(), ImperfectSkinOverlay_Paths.end());
    }
    if (WoundsOverlay_Installed) {
        allAvailable.insert(allAvailable.end(), WoundsOverlay_Paths.begin(), WoundsOverlay_Paths.end());
    }
    if (SkinFeatureOverlay_Installed) {
        allAvailable.insert(allAvailable.end(), SkinFeatureOverlay_Paths.begin(), SkinFeatureOverlay_Paths.end());
    }

    if (allAvailable.empty()) {
        return std::nullopt;
    }

    std::uniform_int_distribution<> dis(0, static_cast<int>(allAvailable.size() - 1));
    return allAvailable[dis(gen)];
}
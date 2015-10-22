#ifndef COMMON
#define COMMON

#include <QtCore>
#include "defines.h"

enum PowerType{
    Mana = 0,
    Rage,
    Focus,
    Energy,
    Happiness,
    Runes = 6,
};

typedef struct {
    quint32 id;
    quint32 unknown1;
    DBCString displayPower;
    DBCString name;
    DBCString name_female;
    DBCString name_male;
    DBCString fileName;
    quint32 spellClassSet;
    quint32 flags;
    quint32 camera;
    quint32 required_expansion;
    quint32 unknown2;
    quint32 unknown3;
    quint32 unknown4;
}ChrClasses;

typedef struct {
    quint32 id;
    quint32 unknown1;
    char *displayPower;
    char * name;
    char * name_female;
    char * name_male;
    char * fileName;
    quint32 spellClassSet;
    quint32 flags;
    quint32 camera;
    quint32 required_expansion;
    quint32 unknown2;
    quint32 unknown3;
    quint32 unknown4;
}WChrClasses;

typedef struct {
    //quint32 id;
    quint32 ID;
    quint32 flags;
    quint32 factionID;
    quint32 ExplorationSoundID;
    quint32 MaleDisplayId;
    quint32 FemaleDisplayId;
    DBCString ClientPrefix;
    quint32 BaseLanguage;
    quint32 creatureType;
    quint32 ResSicknessSpellID;
    quint32 SplashSoundID;
    DBCString clientFileString;
    quint32 cinematicSequenceID;
    quint32 alliance;
    DBCString name_lang;
    DBCString name_female_lang;
    DBCString name_male_lang;
    DBCString facialHairCustomizationMale;
    DBCString facialHairCustomizationFemale;
    DBCString hairCustomization;
    quint32 race_related;
    quint32 unalteredVisualRaceID;
    quint32 uaMaleCreatureSoundDataID;
    quint32 uaFemaleCreatureSoundDataID;
    quint32 charComponentTextureLayoutID;
    quint32 defaultClassID;
    quint32 createScreenFileDataID;
    quint32 selectScreenFileDataID;
    float maleCustomizeOffset[3];
    float femaleCustomizeOffset[3];
    quint32 neutralRaceID;
    quint32 lowResScreenFileDataID;
    quint32 HighResMaleDisplayId;
    quint32 HighResFemaleDisplayId;
    quint32 charComponentTexLayoutHiResID;
    quint32 unknown;
}ChrRaces;

#endif // COMMON


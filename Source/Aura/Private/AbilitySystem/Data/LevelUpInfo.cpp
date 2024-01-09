// Copyright RCP


#include "AbilitySystem/Data/LevelUpInfo.h"

int32 ULevelUpInfo::FindLevelForXP(int32 XP) const
{
	/*for (size_t i = 0; i < LevelUpInformation.Num(); i++)
	{
		if (XP <= LevelUpInformation[i].LevelUpRequirement)
		{
			return i+1;
		}
	}
	return 1;*/

	int32 Level = 1;
	bool bSearching = true;
	while (bSearching)
	{
		//LevelUpInformation[0] is meaningless
		//LevelUpInformation[1] is first level and so on
		if (LevelUpInformation.Num() - 1 <= Level) return Level; //got to cap

		if (XP >= LevelUpInformation[Level].LevelUpRequirement)
		{
			Level++;
		}
		else
		{
			bSearching = false;
		}
	}
	return Level;
}

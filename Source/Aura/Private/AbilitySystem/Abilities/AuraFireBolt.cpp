// Copyright RCP


#include "AbilitySystem/Abilities/AuraFireBolt.h"


FString UAuraFireBolt::GetDescription(int32 Level)
{
	const float ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);

	if (Level == 1)
	{
		return FString::Printf(
			TEXT("<Title>FIRE BOLT</>"
				"\n\n"
				"<Small>Level: </><Level>%d</>\n"
				"<Small>Mana Cost: </><ManaCost>%.1f</>\n"
				"<Small>Cooldown: </><Cooldown>%.1f</>"
				"\n\n"
				"<Default>Launches a bolt of fire, exploding on impact and dealing: </>"
				"<Damage>%d</>"
				"<Default> fire damage with a chance to burn</>"), 
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage
			);
	}
	else
	{
		return FString::Printf(
			TEXT("<Title>FIRE BOLT</>"
				"\n\n"
				"<Small>Level: </><Level>%d</>\n"
				"<Small>Mana Cost: </><ManaCost>%.1f</>\n"
				"<Small>Cooldown: </><Cooldown>%.1f</>"
				"\n\n"
				"<Default>Launches %d bolts of fire, exploding on impact and dealing: </>"
				"<Damage>%d</>"
				"<Default> fire damage with a chance to burn</>"),
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, NumProjectiles),
			ScaledDamage
		); 
	}
	return FString();
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	Level += 1;//next level
	const float ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	
	return FString::Printf(
		TEXT("<Title>NEXT LEVEL</>"
			"\n\n"
			"<Small>Level: </><Level>%d</>\n"
			"<Small>Mana Cost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>"
			"\n\n"
			"<Default>Launches %d bolts of fire, exploding on impact and dealing: </>"
			"<Damage>%d</>"
			"<Default> fire damage with a chance to burn</>"),
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, NumProjectiles),
		ScaledDamage
	);
}
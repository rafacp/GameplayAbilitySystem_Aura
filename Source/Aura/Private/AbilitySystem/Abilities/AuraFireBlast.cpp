// Copyright RCP


#include "AbilitySystem/Abilities/AuraFireBlast.h"
#include "Actor/AuraFireBall.h"

FString UAuraFireBlast::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);

	return FString::Printf(
		TEXT("<Title>FIRE BLAST</>"
			"\n\n"
			"<Small>Level: </><Level>%d</>\n"
			"<Small>Mana Cost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>"
			"\n\n"
			"<Default>Launches %d</>"
			"<Default> fire balls in all directions, each coming back and exploding upon return, causing </>"
			"<Damage>%d</>"
			"<Default> radial fire damage with a chance to burn</>"),
		Level,
		ManaCost,
		Cooldown,
		NumFireBalls,
		ScaledDamage
	);
}

FString UAuraFireBlast::GetNextLevelDescription(int32 Level)
{
	Level += 1;//next level
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);

	return FString::Printf(
		TEXT("<Title>NEXT LEVEL</>"
			"\n\n"
			"<Small>Level: </><Level>%d</>\n"
			"<Small>Mana Cost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>"
			"\n\n"
			"<Default>Launches %d</>"
			"<Default> fire balls in all directions, each coming back and exploding upon return, causing </>"
			"<Damage>%d</>"
			"<Default> radial fire damage with a chance to burn</>"),
		Level,
		ManaCost,
		Cooldown,
		NumFireBalls,
		ScaledDamage
	);
}

TArray<AAuraFireBall*> UAuraFireBlast::SpawnFireBalls()
{
	return TArray<AAuraFireBall*>();
}

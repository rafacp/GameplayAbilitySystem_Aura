// Copyright RCP


#include "AbilitySystem/Abilities/ArcaneShards.h"

FString UArcaneShards::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);

	if (Level == 1)
	{
		return FString::Printf(
			TEXT("<Title>ARCANE SHARDS</>"
				"\n\n"
				"<Small>Level: </><Level>%d</>\n"
				"<Small>Mana Cost: </><ManaCost>%.1f</>\n"
				"<Small>Cooldown: </><Cooldown>%.1f</>"
				"\n\n"
				"<Default>Summons a shard of arcane energy, causing radial damage of </>"
				"<Damage>%d</>"
				"<Default> arcane damage at the shard origin.</>"),
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage
		);
	}
	else
	{
		return FString::Printf(
			TEXT("<Title>ARCANE SHARDS</>"
				"\n\n"
				"<Small>Level: </><Level>%d</>\n"
				"<Small>Mana Cost: </><ManaCost>%.1f</>\n"
				"<Small>Cooldown: </><Cooldown>%.1f</>"
				"\n\n"
				"<Default>Summons %d shards of arcane energy, causing radial damage of </>"
				"<Damage>%d</>"
				"<Default> arcane damage at that shard origins.</>"),
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, MaxNumShards),
			ScaledDamage
		);
	}
	return FString();
}

FString UArcaneShards::GetNextLevelDescription(int32 Level)
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
			"<Default>Summons %d shards of arcane energy, causing radial damage of </>"
			"<Damage>%d</>"
			"<Default> arcane damage at that shard origins.</>"),
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, MaxNumShards),
		ScaledDamage
	);
}
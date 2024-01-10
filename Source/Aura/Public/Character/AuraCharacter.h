// Copyright RCP

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/PlayerInterface.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase, public IPlayerInterface
{
	GENERATED_BODY()
	
public:
	AAuraCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	//PlayerInterface
	virtual int32 FindLevelForXP_Implementation(int32 InXP) const override;

	virtual int32 GetXP_Implementation() const override;
	virtual int32 GetAttributePointsReward_Implementation(int32 Level) const override;
	virtual int32 GetSpellPointsReward_Implementation(int32 Level) const override;

	virtual void AddToXP_Implementation(int32 InXP) override;
	virtual void AddToPlayerLevel_Implementation(int32 InPlayerLevel) override;
	virtual void AddToAttributePoints_Implementation(int32 InAttributePoints) override;
	virtual void AddToSpellPoints_Implementation(int32 InSpellPoints) override;

	virtual void LevelUp_Implementation() override;
	//end PlayerInterface
	
	//Combat Interface
	virtual int32 GetPlayerLevel_Implementation() override;
	//end CombatInterface

protected:
	virtual void InitAbilityActorInfo() override;
};

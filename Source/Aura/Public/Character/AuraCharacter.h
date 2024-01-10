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
	virtual void AddToXP_Implementation(int32 InXP) override;
	
	//Combat Interface
	virtual int32 GetPlayerLevel() override;

protected:
	virtual void InitAbilityActorInfo() override;
};

// Copyright RCP

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	

	// Inherited via IEnemyInterface
public:
	virtual void HightlightActor() override;

	virtual void UnHighlightActor() override;

};

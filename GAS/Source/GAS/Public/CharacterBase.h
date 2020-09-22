// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GameplayAbility.h"
#include "AttributeSetBase.h"
#include "CharacterBase.generated.h"

UCLASS()
class GAS_API ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterDied, ACharacterBase*, Character);
	ACharacterBase();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	void AquireAbility(TSubclassOf<UGameplayAbility> AbilityToAquire);
	UFUNCTION(BlueprintPure, Category = "CharacterBase")
	bool IsHostileToOwner(ACharacterBase* Character) const;
	uint8 GetTeamId() const;

	UFUNCTION()
	void OnHealthChanged(float CurrentHealth, float MaxHealth);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
	UAbilitySystemComponent* AbilitySystemComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "CharacterBase")
	UAttributeSetBase* AttributeSetBase;
	UPROPERTY(BlueprintAssignable)
	UAttributeSetBase::FHealthChanged HealthChanged;
	UPROPERTY(BlueprintAssignable)
	FCharacterDied CharacterDied;

protected:
	virtual void BeginPlay() override;
	bool bIsDied;
	uint8 TeamId;
	void SetTeamId();

private:
	void DisableInput();
};

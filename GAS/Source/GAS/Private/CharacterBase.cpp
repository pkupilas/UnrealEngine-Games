// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"
#include "AttributeSetBase.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "AIController.h"
#include "BrainComponent.h"

ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSetBase = CreateDefaultSubobject<UAttributeSetBase>("AttributeSetBase");
	bIsDied = false;
	TeamId = 255;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	AttributeSetBase->HealthChanged.AddDynamic(this, &ACharacterBase::OnHealthChanged);
	SetTeamId();
}

void ACharacterBase::SetTeamId()
{
	AController* Controller = GetController();
	if (Controller && Controller->IsPlayerController())
	{
		TeamId = 0;
	}
}

void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACharacterBase::AquireAbility(TSubclassOf<UGameplayAbility> AbilityToAquire)
{
	if (!AbilitySystemComponent || !AbilityToAquire)
		return;

	FGameplayAbilitySpecDef AbilitySpecDef = FGameplayAbilitySpecDef();
	AbilitySpecDef.Ability = AbilityToAquire;
	FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilitySpecDef, 1);

	AbilitySystemComponent->GiveAbility(AbilitySpec);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

bool ACharacterBase::IsHostileToOwner(ACharacterBase* Character) const
{
	return Character && Character->GetTeamId() != TeamId;
}

uint8 ACharacterBase::GetTeamId() const
{
	return TeamId;
}

void ACharacterBase::OnHealthChanged(float CurrentHealth, float MaxHealth)
{
	HealthChanged.Broadcast(CurrentHealth, MaxHealth);
	if (CurrentHealth <= 0.0f && !bIsDied)
	{
		bIsDied = true;
		DisableInput();
		CharacterDied.Broadcast(this);
	}
}

void ACharacterBase::DisableInput()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		PlayerController->DisableInput(PlayerController);
	}

	AAIController* AiController = Cast<AAIController>(GetController());
	if (AiController)
	{
		AiController->GetBrainComponent()->StopLogic("Dead");
	}
}
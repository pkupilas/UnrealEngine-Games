// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"
#include "AttributeSetBase.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSetBase = CreateDefaultSubobject<UAttributeSetBase>("AttributeSetBase");
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	AttributeSetBase->HealthChanged.AddDynamic(this, &ACharacterBase::OnHealthChanged);
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
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

void ACharacterBase::OnHealthChanged_Implementation(float CurrentHealth, float MaxHealth)
{
}


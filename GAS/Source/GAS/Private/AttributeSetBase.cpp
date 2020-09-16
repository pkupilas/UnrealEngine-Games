// Fill out your copyright notice in the Description page of Project Settings.
#include "AttributeSetBase.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

UAttributeSetBase::UAttributeSetBase()
{
	Health = 100.0f;
	MaxHealth = 100.0f;
}

void UAttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data)
{
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
		HealthChanged.Broadcast(Health.GetCurrentValue(), MaxHealth.GetCurrentValue());
	}
}

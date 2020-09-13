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
	UProperty* changedProperty = Data.EvaluatedData.Attribute.GetUProperty();
	UProperty* healthProperty = FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health));

	if (changedProperty == healthProperty)
	{
		HealthChanged.Broadcast(Health.GetCurrentValue(), MaxHealth.GetCurrentValue());
	}
}

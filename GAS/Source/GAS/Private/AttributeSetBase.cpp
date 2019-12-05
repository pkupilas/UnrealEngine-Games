// Fill out your copyright notice in the Description page of Project Settings.
#include "AttributeSetBase.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

UAttributeSetBase::UAttributeSetBase()
{
	Health = 200.0f;
}

void UAttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data)
{
	UProperty* changedProperty = Data.EvaluatedData.Attribute.GetUProperty();
	UProperty* healthProperty = FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health));

	if (changedProperty == healthProperty)
	{
		UE_LOG(LogTemp, Warning, TEXT("%f"), Health.GetCurrentValue());
	}
}

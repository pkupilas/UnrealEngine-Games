// Copyright Piotr Kupilas 2017

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	if (PressurePlate != nullptr && OpeningActor != nullptr && PressurePlate->IsOverlappingActor(OpeningActor))
	{
		OpenDoor();
	}
}

void UOpenDoor::OpenDoor() 
{
	AActor* Owner = GetOwner();
	FRotator NewRotator = Owner->GetTransform().GetRotation().Rotator() + FRotator(0.0f, -90.0f, 0.0f);
	Owner->SetActorRotation(NewRotator);
}


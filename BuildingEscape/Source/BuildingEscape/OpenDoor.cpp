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

	OpeningActor = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	if (PressurePlate != nullptr && OpeningActor != nullptr) 
	{
		float currentTime = GetWorld()->GetTimeSeconds();
		if (!IsOpen) 
		{
			if (PressurePlate->IsOverlappingActor(OpeningActor))
			{
				ManageDoorRotation(0.0f, -OpenAngle, 0.0f);
				DoorOpenUpTimeStamp = GetWorld()->GetTimeSeconds();
				IsOpen = true;
			}
		}
		else if (DoorOpenUpTimeStamp + TimeForDoorCloseUp <= currentTime)
		{
			ManageDoorRotation(0.0f, OpenAngle, 0.0f);
			IsOpen = false;
		}
	}
}

void UOpenDoor::ManageDoorRotation(float pitch, float roll, float yaw)
{
	AActor* Owner = GetOwner();
	FRotator NewRotator = Owner->GetTransform().GetRotation().Rotator() + FRotator(pitch, roll, yaw);
	Owner->SetActorRotation(NewRotator);
}


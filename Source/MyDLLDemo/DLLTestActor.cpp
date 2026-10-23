// Fill out your copyright notice in the Description page of Project Settings.


#include "DLLTestActor.h"
#include "MyModLibrary.h"
#include "Engine/Engine.h"

// Sets default values
ADLLTestActor::ADLLTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADLLTestActor::BeginPlay()
{
	Super::BeginPlay();
	bool bLoaded = UMyModLibrary::LoadMyModDLL();

	if (!bLoaded) {
		UE_LOG(LogTemp, Error, TEXT("DLL failed to load!"));
		return;
	}

	float NewSpeed = UMyModLibrary::ScaleSpeedBP(600.0f, 1.5f);

	UE_LOG(LogTemp, Warning, TEXT("DLL Loaded! New Speed: %f"), NewSpeed);


	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("DLL Loaded! Speed = %.0f"), NewSpeed));
	}
}

// Called every frame
void ADLLTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


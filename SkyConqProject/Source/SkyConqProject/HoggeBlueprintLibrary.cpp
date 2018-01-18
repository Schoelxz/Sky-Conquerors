// Fill out your copyright notice in the Description page of Project Settings.

#include "HoggeBlueprintLibrary.h"

#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"

UActorComponent* UHoggeBlueprintLibrary::AddComponentFromClass(TSubclassOf<UActorComponent> ActorComponentClass, AActor* Outer)
{
	UActorComponent* NewComp = nullptr;

	if (ActorComponentClass.Get() != nullptr)
	{
		NewComp = NewObject<UActorComponent>(Outer, ActorComponentClass);
		NewComp->RegisterComponent();
		Outer->AddOwnedComponent(NewComp);
	}

	return NewComp;
}

void UHoggeBlueprintLibrary::ServerTravel(AActor* Instigator, const FString& URL, EServerTravelStatus& Branches, bool bAbsolute, bool bShouldSkipNotify)
{
	Branches = EServerTravelStatus::CouldNotServerTravel;
	if (!GEngine)
		return;
	UWorld* World = GEngine->GetWorldFromContextObjectChecked(Instigator);
	
	if (!World)
		return;

	if (World->ServerTravel(URL, bAbsolute, bShouldSkipNotify))
		Branches = EServerTravelStatus::CouldServerTravel;
		
	return;
}
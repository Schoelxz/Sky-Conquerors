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


int UHoggeBlueprintLibrary::HoggeServerTravel(AActor* Instigator, const FString& FURL, bool bAbsolute, bool bShouldSkipNotify)
{
	if (!GEngine)
		return 1;
	UWorld* World = GEngine->GetWorldFromContextObjectChecked(Instigator);
	
	if (!World)
		return 2;
	
	return World->ServerTravel(FURL, bAbsolute, bShouldSkipNotify) ? 10 : 11;
}
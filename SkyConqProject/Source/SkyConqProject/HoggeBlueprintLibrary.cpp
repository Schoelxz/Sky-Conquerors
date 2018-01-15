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

int UHoggeBlueprintLibrary::ServerTravel(AActor* Instigator, const FString& URL, bool bAbsolute, bool bShouldSkipNotify)
{
	if (!GEngine)
		return 1;
	UWorld* World = GEngine->GetWorldFromContextObjectChecked(Instigator);
	
	if (!World)
		return 2;
	
	return World->ServerTravel(URL, bAbsolute, bShouldSkipNotify) ? 10 : 11;
}
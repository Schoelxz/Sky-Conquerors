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



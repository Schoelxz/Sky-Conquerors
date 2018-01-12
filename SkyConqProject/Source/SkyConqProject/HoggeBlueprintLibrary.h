// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HoggeBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SKYCONQPROJECT_API UHoggeBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="Component|AddComponent")
	static class UActorComponent* AddComponentFromClass(TSubclassOf<UActorComponent> ActorComponentClass, class AActor* Outer);
	
	UFUNCTION(BlueprintCallable, Category="Gameplay")
	static int HoggeServerTravel(class AActor* Instigator, const FString& FURL, bool bAbsolute = true, bool bShouldSkipNotify = true);
};

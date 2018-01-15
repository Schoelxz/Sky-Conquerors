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

	/**
	* Absolute and Skip Notify must be turned off for a working ServerTravel
	*
	* @param Instigator insert joel here
	* @param URL the URL/Level that we are traveling to
	* @param bAbsolute whether we are using relative or absolute travel
	* @param bShouldSkipGameNotify whether to notify the clients/game or not
	*/
	UFUNCTION(BlueprintCallable, Category="Gameplay")
	static int ServerTravel(class AActor* Instigator, const FString& URL, bool bAbsolute = false, bool bShouldSkipNotify = false);
};

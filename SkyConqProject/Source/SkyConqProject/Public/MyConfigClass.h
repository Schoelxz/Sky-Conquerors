// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UCLASS(Config = Game)
class SKYCONQPROJECT_API MyConfigClass
{
	GENERATED_UCLASS_BODY()

		UPROPERTY(Config)
		float ExampleVariable;
};

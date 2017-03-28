// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "SoulVisionStructures.h"
#include "BaseCreature.generated.h"

UCLASS(Blueprintable)
class SOULVISION_API ABaseCreature : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	void CalculateCreatureData();
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Creature Data")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Creature Data", meta = (ClampMin = "5", ClampMax = "100", UIMin = "5", UIMax = "100"))
	uint8 Level = 5;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Creature Data")
	FCreatureData Base;

	// Sets default values for this character's properties
	ABaseCreature();

	// Called when class default values are changed
	virtual void PostInitProperties() override;

	// Called when class values are changed in editor
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	// Returns CameraBoom subobject
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	// Returns FollowCamera subobject
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Creature Controls")
	void MoveForward(float Value);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Creature Controls")
	void MoveRight(float Value);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Creature Controls")
	void PerformAttack(FName Move);

	UFUNCTION(BlueprintCallable, Category = "Creature Functions")
	void UpdateBase(const FCreatureData& NewBase);

	UFUNCTION(BlueprintCallable, Category="Creature Functions")
	FLevelChangeData UpdateLevel(const int32& NewLevel);

	UFUNCTION(BlueprintCallable, Category = "Creature Functions")
	void UpdateStatus(const EStatusTypes& Status);

	UFUNCTION(BlueprintCallable, Category = "Creature Functions")
	void UpdateMoveSet();

	UFUNCTION(BlueprintCallable, Category = "Creature Functions")
	TArray<FName> GetAvailableMoves();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Creature Damage")
	float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

};

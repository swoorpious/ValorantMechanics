﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Wushu_Character.generated.h"

class USkeletalMeshComponent;
class UCameraComponent;
class AWushu_PlayerController;
class ACommonWeapon;

UCLASS()
class VALORANTMECHANICS_API AWushu_Character : public ACharacter
{
	GENERATED_BODY()

public:
	explicit AWushu_Character(const FObjectInitializer& ObjectInitializer);

	bool isJumping = false;
	bool isLanded = false;
	
	
	virtual void Jump() override;
	virtual void Landed(const FHitResult& Hit) override;
	void Walk();
	void Unwalk();
	void AllowPlayerAirControl() const;
	void UnallowPlayerAirControl() const;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Wushu_Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Wushu_MeshCaptureCamera;

	UPROPERTY(EditDefaultsOnly, Category = "Equipped Weapons")
	TSubclassOf<ACommonWeapon> _MeleeWeaponToEquip = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Equipped Weapons")
	TSubclassOf<ACommonWeapon> _SecondaryWeaponToEquip = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Equipped Weapons")
	TSubclassOf<ACommonWeapon> _PrimaryWeaponToEquip = nullptr;

	

	// UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	// UCameraComponent* Wushu_GameplayCaptureCamera;

protected:
	virtual void BeginPlay() override;


	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;


private:
	TObjectPtr<AWushu_PlayerController> PlayerController = nullptr;
	TObjectPtr<UCharacterMovementComponent> PlayerCharacterMovementComponent = nullptr;
	TSubclassOf<ACommonWeapon> currentEquippedWeapon = nullptr;
	TSubclassOf<ACommonWeapon> meleeWeapon = nullptr;
	TSubclassOf<ACommonWeapon> secondaryWeapon = nullptr;
	TSubclassOf<ACommonWeapon> primaryWeapon = nullptr;
	
	
	
	float RunSpeed = 750.0f;
	float WalkSpeed = 400.0f;
	float RegularAcceleration = 3072.0f;

	// jump
	float TimeSinceLanded = 0.0f;
	float BunnyHopTimeThreshold = 0.08f;
	float AfterJumpWalkSpeed = 300.0f; // could be 150.0f
	float JumpStunDuration = 0.2f;
	float WhileJumpingMovementAcceleration = 1024.0f;
	float WhileJumpingWalkSpeed = 150.0f;

};

// Fill out your copyright notice in the Description page of Project Settings.

#include "UEC_Cursor.h"
#include "PlayerAnimInstance.h"
#include "ClickerGM.h"
#include "Inventory.h"
//#include "UEC_ItemAbstract.h"
//#include "UEC_HealPotion.h"
#include "UEC_AIController.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"

#pragma region UEMethods
// Sets default values
AUEC_Cursor::AUEC_Cursor()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	skeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	capsuleCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	inventory = CreateDefaultSubobject<UInventory>(TEXT("Inventory"));

	skeletalMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	capsuleCollider->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	AddOwnedComponent(movement);
	AddOwnedComponent(inventory);
}

// Called when the game starts or when spawned
void AUEC_Cursor::BeginPlay()
{
	Super::BeginPlay();
	InitPlayer();
}

// Called every frame
void AUEC_Cursor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	onPlayerUpdate.Broadcast();
}

// Called to bind functionality to input
void AUEC_Cursor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//SETMOVETARGET BUTTON => CLICK METHOD
	InputComponent->BindAction("SetMoveTarget", IE_Pressed, this, &AUEC_Cursor::Click);
}

#pragma endregion

#pragma region CustomMethods
APlayerController* AUEC_Cursor::GetPlayerController()
{
	return GetWorld()->GetFirstPlayerController();
}

AUEC_CameraManager* AUEC_Cursor::GetCameraManager()
{
	AClickerGM* _gamemode = GetWorld()->GetAuthGameMode<AClickerGM>();
	if (!_gamemode) return nullptr;
	return _gamemode->GetCameraManager();
}

AUEC_FXManager* AUEC_Cursor::GetFXManager()
{
	AClickerGM* _gamemode = GetWorld()->GetAuthGameMode<AClickerGM>();
	if (!_gamemode) return nullptr;
	return _gamemode->GetFXManager();
}

void AUEC_Cursor::InitPlayer()
{
	//INITIALIZE POSITION TO GO TO ACTUAL POSITION
	lastClickPosition = GetActorLocation();

	//GET THE MECANIM
	InitMecanim();

	//CREATE PLAYER CAMERA
	CreatePlayerCamera();
	//EnablePlayerCamera();

	//ADD MOVE & ROTATE TO UPDATE EVENT
	onPlayerUpdate.AddLambda([this]() 
	{
		IDLEtoRUN();
		Rotate();
		onPlayerAtPos.Broadcast();
	});

	onPlayerAtPos.AddLambda([this]()
	{
		//IDLEtoRUN(false);
		if(IsAtPos())ShowFXDestination(false);
	});

	onPlayerMoving.AddLambda([this]()
	{
		//IDLEtoRUN(true);
	});
}

void AUEC_Cursor::InitMecanim()
{
	if (!skeletalMesh) return;
	animator = Cast<UPlayerAnimInstance>(skeletalMesh->GetAnimInstance());
}

void AUEC_Cursor::CreatePlayerCamera()
{
	//GET CAMERA MANAGER
	AUEC_CameraManager* _manager = GetCameraManager();
	if (!_manager) return;

	//CREATE CAMERA WITH PLAYER ID & WANTED SETTINGS
	AUEC_Camera* _camera = _manager->CreateCamera(id, isInside? ownCameraSettingsInside : ownCameraSettingsOutside);


	APlayerController* _controller = GetPlayerController();
	if (!_controller) return;
	_controller->SetViewTarget(_camera);
}

void AUEC_Cursor::EnablePlayerCamera()
{
	//ENABLE THE PLAYER CAMERA
	AUEC_CameraManager* _manager = GetCameraManager();
	if (!_manager) return;
	_manager->Enable(id);
}

void AUEC_Cursor::Click()
{
	//GET POSITION TO GO
	APlayerController* _controller = GetPlayerController();
	if (!_controller)return;

	FHitResult _hit;
	bool _hasHit = _controller->GetHitResultUnderCursorForObjects(allObjectsHitable, true, _hit);
	if (!_hasHit) return;

	lastClickPosition = _hit.Location;

	if (!settings.canMove) return;
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetPlayerController(), lastClickPosition);


	/*AUEC_HealPotion* _potion = NewObject<AUEC_HealPotion>(this);
	if(_potion)
		inventory->Add(_potion);*/

	SpawnFXOnClick();
}

void AUEC_Cursor::SpawnFXOnClick()
{
	//SET THE FX CURSOR TO THE POSITION TO GO
	AUEC_FXManager* _fxManager = GetFXManager();
	if (!_fxManager) return;
	_fxManager->SetPosition(lastClickPosition);
	ShowFXDestination(true);
}

void AUEC_Cursor::ShowFXDestination(bool _show)
{
	AUEC_FXManager* _fxManager = GetFXManager();
	if (!_fxManager) return;
	_fxManager->Hide(!_show);
}

void AUEC_Cursor::ChangeInsideOutside()
{
	isInside = !isInside;
	ModifyPlayerCamOffset();
}

void AUEC_Cursor::ModifyPlayerCamOffset()
{
	AUEC_CameraManager* _manager = GetCameraManager();
	if (!_manager) return;
	if (isInside) {
		_manager->ModifySettings(id, ownCameraSettingsInside);
	}
	else {
		_manager->ModifySettings(id, ownCameraSettingsOutside);
	}
}

FVector AUEC_Cursor::GetLastClickPosition()
{
	return lastClickPosition;
}

bool AUEC_Cursor::IsAtPos()
{
	return FVector::Distance(GetActorLocation(), lastClickPosition) < settings.distanceIsAtPos;
}

void AUEC_Cursor::IDLEtoRUN()
{
	if (!animator) return;
	animator->SetVelocity(movement->Velocity.Size());
}

void AUEC_Cursor::AddInventory(AUEC_ItemAbstract* _item)
{
	inventory->Add(_item);
}

void AUEC_Cursor::Rotate() 
{
	//ROTATE THE PLAYER IF HE CAN
	if (!settings.canRotate || IsAtPos()) return;
	FRotator _newRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), lastClickPosition);
	SetActorRotation(UKismetMathLibrary::RInterpTo(GetActorRotation(), _newRotation, GetWorld()->DeltaTimeSeconds, settings.rotateSpeed));
}
#pragma endregion


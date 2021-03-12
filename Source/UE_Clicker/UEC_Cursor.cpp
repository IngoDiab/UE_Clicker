// Fill out your copyright notice in the Description page of Project Settings.

#include "UEC_Cursor.h"
#include "PlayerAnimInstance.h"
#include "ClickerGM.h"
#include "Kismet/KismetMathLibrary.h"

#pragma region UEMethods
// Sets default values
AUEC_Cursor::AUEC_Cursor()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
			Move();
			Rotate();
		});
}

void AUEC_Cursor::InitMecanim()
{
	USkeletalMeshComponent* _mesh = Cast<USkeletalMeshComponent>(GetComponentByClass(USkeletalMeshComponent::StaticClass()));
	if (!_mesh) return;
	mecanim = Cast<UPlayerAnimInstance>(_mesh->GetAnimInstance());
}

void AUEC_Cursor::CreatePlayerCamera()
{
	//GET CAMERA MANAGER
	AUEC_CameraManager* _manager = GetCameraManager();
	if (!_manager) return;

	/*//CREATE WANTED SETTINGS
	FCameraSettings _settings;
	_settings.target = this;
	_settings.offsetPos = FVector(-460, -10, 500);*/

	//CREATE CAMERA WITH PLAYER ID & WANTED SETTINGS
	AUEC_Camera* _camera = _manager->CreateCamera(id, ownCameraSettings);

	//!\TODO COROUTINE
	APlayerController* _controller = GetPlayerController();
	if (!_controller) return;
	_controller->SetViewTarget(_camera);
	//!\TODO COROUTINE
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

	//SET THE FX CURSOR TO THE POSITION TO GO
	AUEC_FXManager* _fxManager = GetFXManager();
	if (!_fxManager) return;
	_fxManager->SetPosition(lastClickPosition);
	_fxManager->Hide(false);
}

FVector AUEC_Cursor::GetLastClickPosition()
{
	return lastClickPosition;
}

bool AUEC_Cursor::IsAtPos()
{
	return FVector::Distance(GetActorLocation(), lastClickPosition) < 1;
}

void AUEC_Cursor::Move()
{
	if (!stats.canMove) return;

	//HIDE FX CURSOR
	if (IsAtPos())
	{
		if (!mecanim) return;
		mecanim->inputRun = false;
		AUEC_FXManager* _fxManager = GetFXManager();
		if (!_fxManager) return;
		_fxManager->Hide(true);
		return;
	}

	//MOVE THE PLAYER
	SetActorLocation(UKismetMathLibrary::VInterpTo(GetActorLocation(), lastClickPosition, GetWorld()->DeltaTimeSeconds, stats.moveSpeed));
	if (!mecanim) return;
	mecanim->inputRun = true;
}

void AUEC_Cursor::Rotate() 
{
	//ROTATE THE PLAYER IF HE CAN
	if (!stats.canRotate || IsAtPos()) return;
	FRotator _newRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), lastClickPosition);
	SetActorRotation(UKismetMathLibrary::RInterpTo(GetActorRotation(), _newRotation, GetWorld()->DeltaTimeSeconds, stats.rotateSpeed));
}
#pragma endregion


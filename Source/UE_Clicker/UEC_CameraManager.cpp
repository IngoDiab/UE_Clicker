// Fill out your copyright notice in the Description page of Project Settings.


#include "UEC_CameraManager.h"

// Sets default values
AUEC_CameraManager::AUEC_CameraManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUEC_CameraManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUEC_CameraManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUEC_CameraManager::Add(AUEC_Camera* _camera)
{
	if (Exists(_camera->GetID())) return;
	allCameras.Add(_camera->GetID(), _camera);
}

AUEC_Camera* AUEC_CameraManager::Get(int _id)
{
	if (!Exists(_id)) return nullptr;
	return allCameras[_id];
}

void AUEC_CameraManager::Remove(int _id)
{
	if (!Exists(_id)) return;
	allCameras.Remove(_id);
}

void AUEC_CameraManager::Remove(AUEC_Camera* _camera)
{
	if (!Exists(_camera->GetID())) return;
	allCameras.Remove(_camera->GetID());
}

bool AUEC_CameraManager::Exists(int _id)
{
	return allCameras.Contains(_id);
}

bool AUEC_CameraManager::Exists(AUEC_Camera* _camera)
{
	return allCameras.Contains(_camera->GetID());
}

void AUEC_CameraManager::Enable(int _id)
{
	AUEC_Camera* _camera = Get(_id);
	if (!_camera) return;
	UCameraComponent* _camComp = _camera->GetCameraComponent();
	if (!_camComp) return;
	DisableAll();
	_camComp->Activate(true);
}

void AUEC_CameraManager::Disable(int _id)
{
	AUEC_Camera* _camera = Get(_id);
	if (!_camera) return;
	UCameraComponent* _camComp = _camera->GetCameraComponent();
	if (!_camComp) return;
	_camComp->Activate(false);
}

void AUEC_CameraManager::DisableAll()
{
	for(TPair<int, AUEC_Camera*> _camera : allCameras)
	{
		UCameraComponent* _camComp = _camera.Value->GetCameraComponent();
		if (_camComp)
			_camComp->Activate(false);
	}
}

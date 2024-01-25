#include "Stage.h"
#include "Engine/Model.h"
#include"Engine/Camera.h"
Stage::Stage(GameObject* parent)
	:GameObject(parent,"Stage")
{
}

void Stage::Initialize()
{
	hFloor_ = Model::Load("Model\\floor.fbx");
	assert(hFloor_ >= 0);
	hWall_ = Model::Load("Model\\Wall.fbx");
	assert(hFloor_ >= 0);

	Camera::SetPosition({ 6.5,10,-5 });
	Camera::SetTarget({ 6.5,0,5.5 });
}

void Stage::Update()
{
}

void Stage::Draw()
{
	for (int x = 0; x < 15; x++)
	{
		for (int y = 0; y < 15; y++)
		{

			Transform floorTrans;
	        floorTrans.position_ = { 0,0,0 };
	        Model::SetTransform(hFloor_, transform_);
	        Model::Draw(hFloor_);

			Transform WallTrans;
			WallTrans.position_ = { 0,0,0 };
			Model::SetTransform(hWall_, transform_);
			Model::Draw(hWall_);
		}
	}

}

void Stage::Release()
{
}

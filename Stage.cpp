#include "Stage.h"
#include "Engine/Model.h"
#include"Engine/Camera.h"

const int STAGE_X = 15;
const int STAGE_Y = 15;

int stage[STAGE_X][STAGE_Y]
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,00,00,0,0,0,1},
    {1,0,0,0,0,0,0,0,00,00,0,0,0,1},
    {1,0,0,0,1,1,0,0,00,00,0,0,0,1},
    {1,0,0,0,0,0,0,0,00,00,0,0,0,1},
    {1,0,0,0,0,0,0,0,00,00,1,1,0,1},
    {1,0,1,1,0,0,0,0,00,00,0,0,0,1},
    {1,0,0,0,0,0,1,1,00,00,1,1,0,1},
    {1,0,0,0,0,0,0,0,00,00,0,0,0,1},
    {1,0,0,0,0,0,0,0,00,00,0,0,0,1},
    {1,0,0,0,0,0,0,0,00,00,0,0,0,1},
    {1,0,0,1,1,1,0,0,00,00,0,0,0,1},
    {1,0,0,0,0,0,0,0,00,00,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

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
    for (int x = 0; x < STAGE_X; x++)
    {
        for (int y = 0; y < STAGE_Y; y++)
        {
            Transform Trans;
            Trans.position_ = { 0, 0, 0 };
            Trans.position_.x = x;
            Trans.position_.z = y;

            Model::SetTransform(hFloor_, Trans);//floor�̍쐻
            Model::Draw(hFloor_);


            if(x == 0 || x== STAGE_X -1 || y == 0|| y == STAGE_Y -1)
            {
                Model::SetTransform(hWall_, Trans);//wall�̍쐬
                Model::Draw(hWall_);
            }
                
        }
    }
}

void Stage::Release()
{
}

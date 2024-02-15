#include "TitleScene.h"
#include"Engine/SceneManager.h"
#include"Engine/Input.h"
#include"Engine/Image.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene,"),hImage_(-1)
{
}

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
	
	hImage_ = Image::Load("Title1.png");
	assert(hImage_ >= 0);
}

void TitleScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void TitleScene::Release()
{
}

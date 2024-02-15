#include "GameOverScene.h"
#include"Engine/SceneManager.h"
#include"Engine/Input.h"
#include"Engine/Image.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent, "GameOverScene,"), hImage_(-1)
{
}

void GameOverScene::Initialize()
{
}

void GameOverScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}

	hImage_ = Image::Load("GameOver.png");
	assert(hImage_ >= 0);
}

void GameOverScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void GameOverScene::Release()
{
}


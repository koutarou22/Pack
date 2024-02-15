#include "PlayScene.h"
#include "Stage.h"
#include "Player.h"
#include"Gauge.h"
#include"Engine/SceneManager.h"
#include"Engine/Input.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	Instantiate<Gauge>(this);
}

void PlayScene::Update()
{
    // ゲージのオブジェクトを取得
    Gauge* pGauge = (Gauge*)FindObject("Gauge");

    // ゲージの値が0になったらシーンを切り替える
    if (pGauge != nullptr && pGauge->GetCurrentValue() <= 0)
    {
        SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
        if (pSceneManager != nullptr)
        {
            pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
        }
    }
}




void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
//
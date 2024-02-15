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
    // �Q�[�W�̃I�u�W�F�N�g���擾
    Gauge* pGauge = (Gauge*)FindObject("Gauge");

    // �Q�[�W�̒l��0�ɂȂ�����V�[����؂�ւ���
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
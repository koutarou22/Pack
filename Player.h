#pragma once
#include "Engine/GameObject.h"
/// <summary>
/// パックマンを作ってみたい
/// 　　　　　　sato kotaro
/// </summary>
class Stage;

class Player :
    public GameObject
{
	int hModel_;
	float speed_;
	Stage* pStage_;
	int hpMax_;//最大HP
	int hpCrr_;//HP

public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};


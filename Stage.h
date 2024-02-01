#pragma once
#include "Engine/GameObject.h"
#include <vector>

using std::vector;

enum STAGE_OBJ
{
	FLOOR,
	WALL,
};
const int STAGE_FLOOR{ 0 };
const int STAGE_WALL{ 1 };
class Stage :
	public GameObject
{
	int hFloor_;
	int hBlock_;
	vector<vector<int>> stageData_;
	int stageWidth_, stageHeight_;

	
public:

	int GetStageWidth() { return stageWidth_; }
	int GetStageHight() { return stageHeight_; }

	bool IsWall(int _x, int _y);
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Stage(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

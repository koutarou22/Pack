#pragma once
#include "Engine/GameObject.h"
/// <summary>
/// �p�b�N�}��������Ă݂���
/// �@�@�@�@�@�@sato kotaro
/// </summary>
class Player :
    public GameObject
{
	int hModel_;
	float speed_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};


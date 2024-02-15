#pragma once
#include "Engine/GameObject.h"
class Gauge :
    public GameObject
{
	int hGaugeBar_;
	int hGaugeFrame_;

	int gaugeMaxVal_;
	int gaugeCrrVal_;//�J�����g�̒l�i���݂̒l�j
public:

	int GetCurrentValue() const
	{
		return gaugeCrrVal_;
	}

	Gauge(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void SetGaugeVal(int _crr, int _max)
	{
		gaugeMaxVal_ = _max;
		gaugeCrrVal_ = _crr;
	}
};


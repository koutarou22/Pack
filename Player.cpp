#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"
#include"Stage.h"
#include "Gauge.h"


namespace
{
	const float PLAYER_SPEED{ 0.15 };
}

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1), speed_(PLAYER_SPEED), pStage_(nullptr),
	hpCrr_(100), hpMax_(100)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	pStage_ = (Stage *)FindObject("Stage");
	//↑これ何キャスト？
}

void Player::Update()
{

	//enum Dir
	//{
	//	UP,
	//	LEFT,
	//	RIGHT,
	//	DOWN,
	//	NONE
	//};
	XMVECTOR vFront = { 0,0,1,0 };
	XMVECTOR move{ 0,0,0,0 };

	//int moveDir = Dir::NONE;
	//move = XMVECTOR{ 0,0,0,0 };

	if (Input::IsKey(DIK_UP)||Input::IsKey(DIK_W))
	{
		move = XMVECTOR{ 0,0,1,0 };
		//moveDir = Dir::UP;
	}
	if (Input::IsKey(DIK_LEFT)|| Input::IsKey(DIK_A))
	{
		move = XMVECTOR{ -1,0,0,0 };
		//moveDir = Dir::LEFT;
	}
	if (Input::IsKey(DIK_DOWN)|| Input::IsKey(DIK_S))
	{
		move = XMVECTOR{ 0,0,-1,0 };
		//moveDir = Dir::DOWN;
	}
	if (Input::IsKey(DIK_RIGHT)|| Input::IsKey(DIK_D))
	{
		move = XMVECTOR{ 1,0,0,0 };
		//moveDir = Dir::RIGHT;
	}
	
	//もうちょっと応用した姿がこちら↓
	///+++

	int tx, ty;

		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		XMVECTOR posTmp = XMVectorZero();
        posTmp = pos + speed_ * move;

		tx = (int)(XMVectorGetX(posTmp) + 1.0f);
		ty = pStage_->GetStageWidth() - (int)((XMVectorGetZ(posTmp)) + 1.0f);
		
		if (!(pStage_ ->IsWall(tx,ty)))
		{
			pos = posTmp;
		}
		else
		{
			hpCrr_ = hpCrr_ - 2;
			if (hpCrr_)
			{

			}
		}


		
	/*	Debug::Log("(X,Y)=");
		Debug::Log(XMVectorGetX(pos));
		Debug::Log(",");
		//Debug::Log(XMVectorGetZ(pos),true);*/
		//int tx, ty;
		//tx = (int)(XMVectorGetX(pos) +0.5);
		//ty = pStage_->GetStageWidth() - (int)(XMVectorGetZ(pos) + 0.5);

		//Debug::Log("(iX,iZ)=");
		//Debug::Log(tx);
		//Debug::Log(",");
		//Debug::Log(ty);
		//Debug::Log(":");
		//Debug::Log(pStage_->IsWall(tx, ty),true);
		

	if(!XMVector3Equal(move,XMVectorZero()))
	{
		XMStoreFloat3(&(transform_.position_), pos);

		XMMATRIX rot = XMMatrixRotationY(XMConvertToRadians(-XM_PIDIV2));
		XMVECTOR modifiedVec = XMPlaneTransform(move, rot);

		XMVECTOR vdot = XMVector3Dot(vFront, move);

		//これよく使うらしいよ ↓
		assert(XMVectorGetX(vdot) <= 1 && XMVectorGetX(vdot) >= -1);

	     float angle = atan2(XMVectorGetX(move),XMVectorGetZ(move));
	 /*
		CXMVECTOR vCross = XMVector3Cross(vFront, move);
		if (XMVectorGetY(vCross) < 0)
		{
			angle *=  -1;
		}*/

		transform_.rotate_.y = XMConvertToDegrees(angle);


	//float rotAngle[5]{ 0,-90,180,90,180 };
	//transform_.rotate_.y = rotAngle[moveDir];

	}
	
	//++++

	Gauge* pGauge = (Gauge*)FindObject("Gauge");
	pGauge->SetGaugeVal(hpCrr_, hpMax_);
	
	
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}


#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"



namespace
{
	const float PLAYER_SPEED{ 1.0f };
}

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1),speed_(1.0f)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
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

	if (Input::IsKeyDown(DIK_UP)||Input::IsKeyDown(DIK_W))
	{
		move = XMVECTOR{ 0,0,1,0 };
		//moveDir = Dir::UP;
	}
	if (Input::IsKeyDown(DIK_LEFT)|| Input::IsKeyDown(DIK_A))
	{
		move = XMVECTOR{ -1,0,0,0 };
		//moveDir = Dir::LEFT;
	}
	if (Input::IsKeyDown(DIK_DOWN)|| Input::IsKeyDown(DIK_S))
	{
		move = XMVECTOR{ 0,0,-1,0 };
		//moveDir = Dir::DOWN;
	}
	if (Input::IsKeyDown(DIK_RIGHT)|| Input::IsKeyDown(DIK_D))
	{
		move = XMVECTOR{ 1,0,0,0 };
		//moveDir = Dir::RIGHT;
	}


	//Ç‡Ç§ÇøÇÂÇ¡Ç∆âûópÇµÇΩépÇ™Ç±ÇøÇÁÅ´
	///+++

		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos + speed_ * move;
		Debug::Log("(X,Y)=");
		Debug::Log(XMVectorGetX(pos));
		Debug::Log(",");
		Debug::Log(XMVectorGetZ(pos),true);

		

	if(!XMVector3Equal(move,XMVectorZero()))
	{
		XMStoreFloat3(&(transform_.position_), pos);


		XMVECTOR vdot = XMVector3Dot(vFront, move);

		//Ç±ÇÍÇÊÇ≠égÇ§ÇÁÇµÇ¢ÇÊ Å´
		assert(XMVectorGetX(vdot) <= 1 && XMVectorGetX(vdot) >= -1);

		float angle = acos(XMVectorGetX(vdot));
	 
		CXMVECTOR vCross = XMVector3Cross(vFront, move);
		if (XMVectorGetY(vCross) < 0)
		{
			angle *=  -1;
		}

		transform_.rotate_.y = XMConvertToDegrees(angle);


	//float rotAngle[5]{ 0,-90,180,90,180 };
	//transform_.rotate_.y = rotAngle[moveDir];

	}

	//++++
	
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}


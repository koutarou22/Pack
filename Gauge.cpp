#include "Gauge.h"
#include "Engine/Image.h"

Gauge::Gauge(GameObject* parent)
	:GameObject(parent, "Gauge"), hGaugeBar_(-1), hGaugeFrame_(-1), gaugeMaxVal_(100), gaugeCrrVal_(100)
{
}

void Gauge::Initialize()
{
	hGaugeBar_ = Image::Load("Life.png");
	assert(hGaugeBar_ >= 0);
	hGaugeFrame_ = Image::Load("Gauag.png");
	assert(hGaugeFrame_ >= 0);

	transform_.position_.x = -0.8f;
	transform_.position_.y = 0.93f;

}

void Gauge::Update()
{
}

void Gauge::Draw()
{
    Transform tr = transform_;
    float scale = (float)gaugeCrrVal_ / (float)gaugeMaxVal_;

    tr.scale_.x = scale;
    tr.position_.x = transform_.position_.x - (transform_.scale_.x * (1.0f - scale) / 5.0f);

    Image::SetTransform(hGaugeBar_, tr);
    Image::Draw(hGaugeBar_);

    Image::SetTransform(hGaugeFrame_, transform_);
    Image::Draw(hGaugeFrame_);
}


void Gauge::Release()
{
}

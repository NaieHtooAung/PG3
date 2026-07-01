#include "Bullet.h"
#include <Novice.h>

void Bullet::Initialize(const Vector2& position, float speed, float size) {
	position_ = position;
	speed_ = speed;
	size_ = size;
	isAlive_ = true;
}

void Bullet::Update() {
	if (!isAlive_) {
		return;
	}
	position_.y -= speed_;
	if (position_.y < -size_ * 40.0f) {
		isAlive_ = false;
	}
}

void Bullet::Draw(int textureHandle) const {
	if (!isAlive_) {
		return;
	}
	Novice::DrawSprite(static_cast<int>(position_.x), static_cast<int>(position_.y), textureHandle, size_, size_, 0.0f, 0xffffffff);
}

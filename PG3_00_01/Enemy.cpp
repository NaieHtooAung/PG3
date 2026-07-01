#include "Enemy.h"
#include <Novice.h>

void Enemy::Initialize() {
	position_ = {10.0f, 10.0f};
	speed_ = 5.0f;
	health_ = 400;
	hitFlashTimer_ = 0;
	textureHandle_ = Novice::LoadTexture("./image/enemy.png");
}

void Enemy::Update() {
	if (!IsAlive()) return;

	position_.x += speed_;
	if (position_.x > 1280.0f - (kSize_ + 170.0f)) speed_ *= -1.0f;
	if (position_.x < (kSize_ - 15.0f)) speed_ *= -1.0f;

	if (hitFlashTimer_ > 0) hitFlashTimer_--;
}

void Enemy::TakeDamage(int damage) {
	health_ -= damage;
	if (health_ < 0) health_ = 0;
	hitFlashTimer_ = 8;
}

void Enemy::Draw() const {
	if (!IsAlive()) return;
	unsigned int color = (hitFlashTimer_ > 0) ? RED : WHITE;
	Novice::DrawSprite(static_cast<int>(position_.x), static_cast<int>(position_.y), textureHandle_, kSize_, kSize_, 0.0f, color);
}

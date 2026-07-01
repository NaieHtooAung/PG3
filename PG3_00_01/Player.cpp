#include "Player.h"
#include "InputManager.h"
#include <Novice.h>
#include <cmath>

void Player::Initialize() {
	position_ = {600.0f, 800.0f};
	health_ = 100.0f;
	specialGauge_ = 0;
	hitFlashTimer_ = 0;

	textureHandle_ = Novice::LoadTexture("./image/player.png");
	bulletTextureHandle_ = Novice::LoadTexture("./image/bullet.png");
	specialTextureHandle_ = Novice::LoadTexture("./image/special.png");
	deadTextureHandle_ = Novice::LoadTexture("./image/playerdie.png");
	shotSeHandle_ = Novice::LoadAudio("./Songs/playershot.mp3");
	specialSeHandle_ = Novice::LoadAudio("./Songs/specialshot.mp3");
}

void Player::Move() {
	InputManager* input = InputManager::GetInstance();
	float dirX = 0.0f;
	float dirY = 0.0f;
	if (input->IsKeyDown(DIK_W)) dirY -= 1.0f;
	if (input->IsKeyDown(DIK_S)) dirY += 1.0f;
	if (input->IsKeyDown(DIK_D)) dirX += 1.0f;
	if (input->IsKeyDown(DIK_A)) dirX -= 1.0f;

	float length = std::sqrtf(dirX * dirX + dirY * dirY);
	if (length != 0.0f) {
		dirX /= length;
		dirY /= length;
	}
	position_.x += dirX * kSpeed_;
	position_.y += dirY * kSpeed_;

	if (position_.x > 1280.0f - (kSize_ + 128.0f)) position_.x = 1280.0f - (kSize_ + 128.0f);
	if (position_.x < kSize_) position_.x = kSize_;
	if (position_.y > 720.0f - (kSize_ + 150.0f)) position_.y = 720.0f - (kSize_ + 150.0f);
	if (position_.y < kSize_ - 10.0f) position_.y = kSize_ - 10.0f;
}

void Player::Shoot() {
	InputManager* input = InputManager::GetInstance();

	if (!bullet_.IsAlive() && !specialBullet_.IsAlive() && input->IsKeyTrigger(DIK_SPACE)) {
		Vector2 pos = {position_.x + 34.0f, position_.y - 60.0f};
		bullet_.Initialize(pos, 30.0f, 1.0f);
		Novice::PlayAudio(shotSeHandle_, 0, 0.1f);
	}

	if (specialGauge_ >= 100 && !specialBullet_.IsAlive()) {
		Vector2 pos = {position_.x, position_.y - 60.0f};
		specialBullet_.Initialize(pos, 32.0f, 2.0f);
		Novice::PlayAudio(specialSeHandle_, 0, 0.1f);
	}

	bullet_.Update();
	specialBullet_.Update();

	if (specialBullet_.IsAlive()) {
		specialGauge_--;
		if (specialGauge_ < 0) specialGauge_ = 0;
	}
}

void Player::AddSpecialGauge(int amount) {
	specialGauge_ += amount;
	if (specialGauge_ > 100) specialGauge_ = 100;
}

void Player::TakeDamage(float damage) {
	health_ -= damage;
	if (health_ < 0.0f) health_ = 0.0f;
	hitFlashTimer_ = 10;
}

void Player::Update() {
	if (IsDead()) return;
	Move();
	Shoot();
	if (hitFlashTimer_ > 0) hitFlashTimer_--;
}

void Player::Draw() const {
	if (IsDead()) {
		Novice::DrawSprite(static_cast<int>(position_.x), static_cast<int>(position_.y), deadTextureHandle_, 4.0f, 4.0f, 0.0f, 0xffffffff);
		return;
	}

	unsigned int color = (hitFlashTimer_ > 0) ? RED : WHITE;
	Novice::DrawSprite(static_cast<int>(position_.x), static_cast<int>(position_.y), textureHandle_, kSize_, kSize_, 0.0f, color);

	bullet_.Draw(bulletTextureHandle_);
	specialBullet_.Draw(specialTextureHandle_);

	Novice::DrawBox(0, 700, static_cast<int>(health_), 10, 0.0f, GREEN, kFillModeSolid);
}

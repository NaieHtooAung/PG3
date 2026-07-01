#pragma once
#include "Vector2.h"
#include "Bullet.h"

// 自機クラス（移動・通常弾・必殺弾・体力を管理）
class Player {
public:
	void Initialize();
	void Update();
	void Draw() const;

	const Vector2& GetPosition() const { return position_; }
	float GetSize() const { return kSize_; }
	float GetHealth() const { return health_; }
	bool IsDead() const { return health_ <= 0.0f; }
	void TakeDamage(float damage);

	Bullet& GetBullet() { return bullet_; }
	Bullet& GetSpecialBullet() { return specialBullet_; }
	int GetSpecialGauge() const { return specialGauge_; }
	void AddSpecialGauge(int amount);

private:
	void Move();
	void Shoot();

	Vector2 position_ = {600.0f, 800.0f};
	const float kSize_ = 2.0f;
	const float kSpeed_ = 5.0f;
	float health_ = 100.0f;

	Bullet bullet_;
	Bullet specialBullet_;
	int specialGauge_ = 0;

	int textureHandle_ = 0;
	int bulletTextureHandle_ = 0;
	int specialTextureHandle_ = 0;
	int deadTextureHandle_ = 0;
	int shotSeHandle_ = 0;
	int specialSeHandle_ = 0;

	int hitFlashTimer_ = 0;
};

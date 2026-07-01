#pragma once
#include "Vector2.h"

// 敵キャラクラス（左右移動・体力管理）
class Enemy {
public:
	void Initialize();
	void Update();
	void Draw() const;

	const Vector2& GetPosition() const { return position_; }
	float GetSize() const { return kSize_; }
	int GetHealth() const { return health_; }
	bool IsAlive() const { return health_ > 0; }
	void TakeDamage(int damage);

private:
	Vector2 position_ = {10.0f, 10.0f};
	const float kSize_ = 0.19f;
	float speed_ = 5.0f;
	int health_ = 400;

	int textureHandle_ = 0;
	int hitFlashTimer_ = 0;
};

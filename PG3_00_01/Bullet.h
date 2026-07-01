#pragma once
#include "Vector2.h"

// プレイヤーの通常弾・必殺弾で共用するシンプルな弾クラス
class Bullet {
public:
	void Initialize(const Vector2& position, float speed, float size);
	void Update();
	void Draw(int textureHandle) const;

	bool IsAlive() const { return isAlive_; }
	void Kill() { isAlive_ = false; }
	const Vector2& GetPosition() const { return position_; }
	float GetSize() const { return size_; }

private:
	Vector2 position_ = {0.0f, 0.0f};
	float speed_ = 0.0f;
	float size_ = 1.0f;
	bool isAlive_ = false;
};

#pragma once
#include "IScene.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyBullet.h"

class GameManager;

// ステージ（プレイ中）シーン
class StageScene : public IScene {
public:
	explicit StageScene(GameManager* gameManager);
	~StageScene() override = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	void UpdateEnemyBullets();
	void CheckCollisions();

	GameManager* gameManager_ = nullptr;

	Player player_;
	Enemy enemy_;

	static const int kEnemyBulletCount = 5;
	EnemyBullet enemyBullets_[kEnemyBulletCount];
	int enemyBulletTimer_[kEnemyBulletCount] = {};

	int backgroundHandle_ = 0;
	int enemyBulletTextureHandle_ = 0;
	int bgmHandle_ = 0;
	int playBgmVoice_ = -1;
	int playerHitSeHandle_ = 0;
	int enemyHitSeHandle_ = 0;
	int specialHitSeHandle_ = 0;

	int backgroundScrollY_ = 0;
};

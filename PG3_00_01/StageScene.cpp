#include "StageScene.h"
#include "GameManager.h"
#include "InputManager.h"
#include <Novice.h>
#include <cmath>
#include <cstdlib>

StageScene::StageScene(GameManager* gameManager) : gameManager_(gameManager) {}

void StageScene::Initialize() {
	player_.Initialize();
	enemy_.Initialize();

	backgroundHandle_ = Novice::LoadTexture("./image/gamescene.png");
	enemyBulletTextureHandle_ = Novice::LoadTexture("./image/enemybullet.png");
	bgmHandle_ = Novice::LoadAudio("./Songs/Game_Scene.wav");
	playerHitSeHandle_ = Novice::LoadAudio("./Songs/playerhit.mp3");
	enemyHitSeHandle_ = Novice::LoadAudio("./Songs/enemyhit.mp3");
	specialHitSeHandle_ = Novice::LoadAudio("./Songs/specialhit.mp3");

	backgroundScrollY_ = 0;
	playBgmVoice_ = Novice::PlayAudio(bgmHandle_, 1, 1.0f);

	for (int i = 0; i < kEnemyBulletCount; ++i) {
		enemyBulletTimer_[i] = 120 + i * 20;
	}
}

void StageScene::UpdateEnemyBullets() {
	for (int i = 0; i < kEnemyBulletCount; ++i) {
		if (!enemyBullets_[i].IsAlive()) {
			enemyBulletTimer_[i]--;
			if (enemyBulletTimer_[i] <= 0) {
				Vector2 pos;
				pos.x = static_cast<float>(rand() % (1280 - 60) + 30);
				pos.y = static_cast<float>(rand() % (200 - 60) + 30);
				enemyBullets_[i].Initialize(pos, 20.0f, 1.0f);
				enemyBulletTimer_[i] = 180;
			}
		} else {
			enemyBullets_[i].Update();
		}
	}
}

void StageScene::CheckCollisions() {
	// 通常弾が敵に当たったか
	if (player_.GetBullet().IsAlive()) {
		Vector2 ePos = enemy_.GetPosition();
		Vector2 bPos = player_.GetBullet().GetPosition();
		float dx = (ePos.x + 140.0f) - bPos.x;
		float dy = ePos.y - bPos.y;
		float distance = std::sqrtf(dx * dx + dy * dy);
		float radius = (enemy_.GetSize() + 80.0f) + player_.GetBullet().GetSize() + 20.0f;
		if (distance <= radius) {
			enemy_.TakeDamage(10);
			player_.AddSpecialGauge(10);
			player_.GetBullet().Kill();
			Novice::PlayAudio(enemyHitSeHandle_, 0, 1.0f);
		}
	}

	// 必殺弾が敵に当たったか
	if (player_.GetSpecialBullet().IsAlive()) {
		Vector2 ePos = enemy_.GetPosition();
		Vector2 sPos = player_.GetSpecialBullet().GetPosition();
		float dx = (ePos.x + 110.0f) - sPos.x;
		float dy = ePos.y - sPos.y;
		float distance = std::sqrtf(dx * dx + dy * dy);
		float radius = (enemy_.GetSize() + 60.0f) + player_.GetSpecialBullet().GetSize() + 20.0f;
		if (distance <= radius) {
			enemy_.TakeDamage(3);
			Novice::PlayAudio(specialHitSeHandle_, 0, 0.1f);
		}
	}

	// 敵弾が自機に当たったか
	for (int i = 0; i < kEnemyBulletCount; ++i) {
		if (!enemyBullets_[i].IsAlive()) continue;

		Vector2 pPos = player_.GetPosition();
		Vector2 bPos = enemyBullets_[i].GetPosition();
		float dx = (pPos.x - 40.0f) - bPos.x;
		float dy = pPos.y - bPos.y;
		float distance = std::sqrtf(dx * dx + dy * dy);
		float radius = (player_.GetSize() / 2.0f + enemyBullets_[i].GetSize() / 2.0f + 50.0f);

		if (distance <= radius) {
			player_.TakeDamage(20.0f);
			enemyBullets_[i].Kill();
			Novice::PlayAudio(playerHitSeHandle_, 0, 1.0f);
		}
	}
}

void StageScene::Update() {
	backgroundScrollY_ += 5;
	if (backgroundScrollY_ > 720) backgroundScrollY_ = 0;

	player_.Update();
	enemy_.Update();
	UpdateEnemyBullets();
	CheckCollisions();

	if (!enemy_.IsAlive()) {
		Novice::StopAudio(playBgmVoice_);
		gameManager_->ChangeScene(SceneType::kClear);
		return;
	}
	if (player_.IsDead()) {
		Novice::StopAudio(playBgmVoice_);
		gameManager_->ChangeScene(SceneType::kGameOver);
		return;
	}
}

void StageScene::Draw() {
	Novice::DrawSprite(0, backgroundScrollY_, backgroundHandle_, 5.0f, 3.0f, 0.0f, 0xffffffff);
	Novice::DrawSprite(0, backgroundScrollY_ - 720, backgroundHandle_, 5.0f, 3.0f, 0.0f, 0xffffffff);

	enemy_.Draw();
	player_.Draw();

	for (int i = 0; i < kEnemyBulletCount; ++i) {
		enemyBullets_[i].Draw(enemyBulletTextureHandle_);
	}

	// 敵HPバー・必殺技ゲージ
	Novice::DrawBox(0, 0, enemy_.GetHealth(), 15, 0.0f, RED, kFillModeSolid);
	Novice::DrawBox(0, 20, player_.GetSpecialGauge(), 30, 0.0f, BLUE, kFillModeSolid);
}

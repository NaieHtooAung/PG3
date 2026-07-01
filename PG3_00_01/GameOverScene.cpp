#include "GameOverScene.h"
#include "GameManager.h"
#include "InputManager.h"
#include <Novice.h>

GameOverScene::GameOverScene(GameManager* gameManager) : gameManager_(gameManager) {}

void GameOverScene::Initialize() {
	backgroundHandle_ = Novice::LoadTexture("./image/playerdie.png");
	bgmHandle_ = Novice::LoadAudio("./Songs/Game_Over.wav");
	playBgmVoice_ = Novice::PlayAudio(bgmHandle_, 1, 1.0f);
}

void GameOverScene::Update() {
	if (InputManager::GetInstance()->IsKeyTrigger(DIK_R)) {
		Novice::StopAudio(playBgmVoice_);
		gameManager_->ChangeScene(SceneType::kStage);
	}
}

void GameOverScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	Novice::DrawSprite(140, 0, backgroundHandle_, 2.0f, 1.5f, 0.0f, 0xffffffff);
}

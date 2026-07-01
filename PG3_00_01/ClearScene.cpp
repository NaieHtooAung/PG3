#include "ClearScene.h"
#include "GameManager.h"
#include "InputManager.h"
#include <Novice.h>

ClearScene::ClearScene(GameManager* gameManager) : gameManager_(gameManager) {}

void ClearScene::Initialize() {
	backgroundHandle_ = Novice::LoadTexture("./image/youwin.png");
	bgmHandle_ = Novice::LoadAudio("./Songs/Win.mp3");
	playBgmVoice_ = Novice::PlayAudio(bgmHandle_, 1, 1.0f);
}

void ClearScene::Update() {
	if (InputManager::GetInstance()->IsKeyTrigger(DIK_E)) {
		Novice::StopAudio(playBgmVoice_);
		gameManager_->ChangeScene(SceneType::kTitle);
	}
}

void ClearScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	Novice::DrawSprite(250, 100, backgroundHandle_, 1.5f, 1.0f, 0.0f, 0xffffffff);
}

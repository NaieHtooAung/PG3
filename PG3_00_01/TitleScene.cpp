#include "TitleScene.h"
#include "GameManager.h"
#include "InputManager.h"
#include <Novice.h>

TitleScene::TitleScene(GameManager* gameManager) : gameManager_(gameManager) {}

void TitleScene::Initialize() {
	backgroundHandle_ = Novice::LoadTexture("./image/MainScreen.png");
	bgmHandle_ = Novice::LoadAudio("./Songs/Start.mp3");
	playBgmVoice_ = Novice::PlayAudio(bgmHandle_, 1, 1.0f);
}

void TitleScene::Update() {
	if (InputManager::GetInstance()->IsKeyTrigger(DIK_E)) {
		Novice::StopAudio(playBgmVoice_);
		gameManager_->ChangeScene(SceneType::kStage);
	}
}

void TitleScene::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
	Novice::DrawSprite(260, 0, backgroundHandle_, 3.0f, 3.0f, 0.0f, 0xffffffff);
}

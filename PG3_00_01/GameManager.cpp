#include "GameManager.h"
#include "InputManager.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include "GameOverScene.h"
#include <Novice.h>

namespace {
	const char kWindowTitle[] = "GC1C_08_ネイ_トゥーアウン";
}

GameManager::GameManager() {
	Novice::Initialize(kWindowTitle, 1280, 720);
	ChangeScene(SceneType::kTitle);
}

GameManager::~GameManager() {
	delete scene_;
	Novice::Finalize();
}

IScene* GameManager::CreateScene(SceneType type) {
	switch (type) {
	case SceneType::kTitle:
		return new TitleScene(this);
	case SceneType::kStage:
		return new StageScene(this);
	case SceneType::kClear:
		return new ClearScene(this);
	case SceneType::kGameOver:
		return new GameOverScene(this);
	}
	return nullptr;
}

void GameManager::ChangeScene(SceneType nextScene) {
	delete scene_;
	scene_ = CreateScene(nextScene);
	scene_->Initialize();
}

int GameManager::Run() {
	while (Novice::ProcessMessage() == 0) {
		Novice::BeginFrame();

		InputManager::GetInstance()->Update();

		scene_->Update();
		scene_->Draw();

		Novice::EndFrame();

		if (InputManager::GetInstance()->IsKeyTrigger(DIK_ESCAPE)) {
			break;
		}
	}
	return 0;
}

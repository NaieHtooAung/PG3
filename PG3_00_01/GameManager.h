#pragma once
#include "IScene.h"
#include "SceneType.h"

// 各シーンの生成・切り替え・メインループを管理するクラス（State Patternの「Context」役）
class GameManager {
public:
	GameManager();
	~GameManager();

	// Noviceのメインループを実行する
	int Run();

	// シーンを切り替える（状態遷移）
	void ChangeScene(SceneType nextScene);

private:
	IScene* CreateScene(SceneType type);

	IScene* scene_ = nullptr;
};

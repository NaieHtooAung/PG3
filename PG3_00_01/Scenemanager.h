#pragma once
#include "IScene.h"
#include <memory>

// ステートパターンの「Context」役。現在のシーンを保持し、
// シーンからの遷移リクエストを見て切り替えを行う。
class SceneManager {
public:
	SceneManager();
	~SceneManager();

	void Update();
	void Draw();

private:
	std::unique_ptr<IScene> CreateScene(SceneType type);
	void ChangeScene(SceneType type);

	std::unique_ptr<IScene> currentScene_;
	SceneType currentSceneType_ = SceneType::kTitle;
};

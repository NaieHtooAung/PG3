#pragma once
#include "IScene.h"

class GameManager;

// クリア（勝利）シーン
class ClearScene : public IScene {
public:
	explicit ClearScene(GameManager* gameManager);
	~ClearScene() override = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	GameManager* gameManager_ = nullptr;
	int backgroundHandle_ = 0;
	int bgmHandle_ = 0;
	int playBgmVoice_ = -1;
};

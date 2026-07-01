#pragma once
#include "IScene.h"

class GameManager;

// ゲームオーバー（自機死亡）シーン
class GameOverScene : public IScene {
public:
	explicit GameOverScene(GameManager* gameManager);
	~GameOverScene() override = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	GameManager* gameManager_ = nullptr;
	int backgroundHandle_ = 0;
	int bgmHandle_ = 0;
	int playBgmVoice_ = -1;
};

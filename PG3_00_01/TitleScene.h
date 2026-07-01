#pragma once
#include "IScene.h"

class GameManager;

// タイトルシーン
class TitleScene : public IScene {
public:
	explicit TitleScene(GameManager* gameManager);
	~TitleScene() override = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	GameManager* gameManager_ = nullptr;
	int backgroundHandle_ = 0;
	int bgmHandle_ = 0;
	int playBgmVoice_ = -1;
};

#pragma once
#include <Novice.h>

// キー入力をまとめて管理するシングルトンクラス（インプットマネージャ）
class InputManager {
public:
	static InputManager* GetInstance();

	// 毎フレーム先頭で呼び出す
	void Update();

	// 押している間ずっとtrue
	bool IsKeyDown(int keyCode) const;
	// 押した瞬間のみtrue
	bool IsKeyTrigger(int keyCode) const;

private:
	InputManager() = default;
	~InputManager() = default;
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;

	char keys_[256] = {};
	char preKeys_[256] = {};
};

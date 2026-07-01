#include "InputManager.h"
#include <cstring>

InputManager* InputManager::GetInstance() {
	static InputManager instance;
	return &instance;
}

void InputManager::Update() {
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}

bool InputManager::IsKeyDown(int keyCode) const {
	return keys_[keyCode] != 0;
}

bool InputManager::IsKeyTrigger(int keyCode) const {
	return keys_[keyCode] != 0 && preKeys_[keyCode] == 0;
}

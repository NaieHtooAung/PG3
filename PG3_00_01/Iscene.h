#pragma once

// シーンの基底となるインターフェースクラス（State Patternの「State」役）
class IScene {
public:
	virtual ~IScene() = default;

	// シーン開始時に一度だけ呼ばれる初期化
	virtual void Initialize() = 0;
	// 毎フレームの更新
	virtual void Update() = 0;
	// 毎フレームの描画
	virtual void Draw() = 0;
};

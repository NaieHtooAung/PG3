#include <stdio.h>
#include <stdlib.h>

/* Enemyクラス */
struct Enemy {
    typedef void (Enemy::* StateFunc)();  // メンバ関数ポインタの型定義

    StateFunc currentState;
    int m_timer;

    /* 状態①：接近 */
    void approach() {
        printf("[接近中] 敵がプレイヤーに近づいている...\n");
        m_timer++;
        if (m_timer >= 3) {
            m_timer = 0;
            currentState = &Enemy::shoot;
        }
    }

    /* 状態②：射撃 */
    void shoot() {
        printf("[射撃中] 敵が攻撃している！\n");
        m_timer++;
        if (m_timer >= 2) {
            m_timer = 0;
            currentState = &Enemy::retreat;
        }
    }

    /* 状態③：離脱 */
    void retreat() {
        printf("[離脱中] 敵が逃げている...\n");
        m_timer++;
        if (m_timer >= 2) {
            m_timer = 0;
            currentState = &Enemy::approach;
        }
    }

    /* 更新処理 */
    void update() {
        (this->*currentState)();  // メンバ関数ポインタの呼び出し
    }

    /* 初期化 */
    void init() {
        currentState = &Enemy::approach;
        m_timer = 0;
    }
};

int main() {
    system("chcp 65001 > nul");

    Enemy enemy;
    enemy.init();

    printf("=== 敵の状態遷移シミュレーション ===\n");
    for (int i = 0; i < 10; i++) {
        printf("フレーム %d: ", i + 1);
        enemy.update();
    }

    return 0;
}
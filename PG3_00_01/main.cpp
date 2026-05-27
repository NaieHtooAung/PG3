#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/* 前方宣言 */
typedef struct Enemy Enemy;

/* 関数ポインタの型定義 */
typedef void (*StateFunc)(Enemy*);

/* Enemyの構造体 */
struct Enemy {
    StateFunc currentState;
    int m_timer;
};

/* 前方宣言 */
void approach(Enemy* e);
void shoot(Enemy* e);
void retreat(Enemy* e);

/* 状態①：接近 */
void approach(Enemy* e) {
    printf("[接近中] 敵がプレイヤーに近づいている...\n");
    e->m_timer++;
    if (e->m_timer >= 3) {
        e->m_timer = 0;
        e->currentState = shoot;
    }
}

/* 状態②：射撃 */
void shoot(Enemy* e) {
    printf("[射撃中] 敵が攻撃している！\n");
    e->m_timer++;
    if (e->m_timer >= 2) {
        e->m_timer = 0;
        e->currentState = retreat;
    }
}

/* 状態③：離脱 */
void retreat(Enemy* e) {
    printf("[離脱中] 敵が逃げている...\n");
    e->m_timer++;
    if (e->m_timer >= 2) {
        e->m_timer = 0;
        e->currentState = approach;
    }
}

/* 更新処理 */
void update(Enemy* e) {
    e->currentState(e);
}

/* 初期化 */
void initEnemy(Enemy* e) {
    e->currentState = approach;
    e->m_timer = 0;
}

int main() {
    system("chcp 65001 > nul");

    Enemy enemy;
    initEnemy(&enemy);

    printf("=== 敵の状態遷移シミュレーション ===\n");
    for (int i = 0; i < 10; i++) {
        printf("フレーム %d: ", i + 1);
        update(&enemy);
    }

    return 0;
}
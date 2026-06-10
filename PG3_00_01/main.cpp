#include <stdio.h>
#include <cstdlib>
#include <Windows.h>
#include <cmath>

// ===== PowerUpItem =====
class PowerUpItem {
private:
    int attackBonus;
    char type[32];
public:
    PowerUpItem(int bonus, const char* t) {
        attackBonus = bonus;
        for (int i = 0; i < 32; i++) type[i] = t[i];
    }
    int getBonus() { return attackBonus; }
    void applyEffect() {
        printf("パワーアップ! 攻撃力 +%d\n", attackBonus);
    }
    void spawn() {
        printf("アイテム '%s' が出現した!\n", type);
    }
};

// ===== Bullet =====
class Bullet {
private:
    float speed;
    int damage;
public:
    Bullet(float s, int d) {
        speed = s;
        damage = d;
    }
    void move() {
        printf("弾が速度 %.1f で移動中...\n", speed);
    }
    void hitCheck() {
        printf("弾がヒット! ダメージ: %d\n", damage);
    }
};

// ===== Player =====
class Player {
private:
    int life;
    int attackPower;
    float speed;
public:
    Player(int l, int atk, float spd) {
        life = l;
        attackPower = atk;
        speed = spd;
    }
    int getLife() { return life; }
    int getAttackPower() { return attackPower; }

    void move() {
        printf("プレイヤーが速度 %.1f で移動中\n", speed);
    }
    Bullet* shoot() {
        printf("プレイヤーが弾を発射! 攻撃力: %d\n", attackPower);
        return new Bullet(10.0f, attackPower);
    }
    void collectItem(PowerUpItem* item) {
        attackPower += item->getBonus();
        item->applyEffect();
        printf("現在の攻撃力: %d\n", attackPower);
    }
    void takeDamage(int dmg) {
        life -= dmg;
        printf("プレイヤーがダメージを受けた! 残りライフ: %d\n", life);
        if (life <= 0) {
            printf("ゲームオーバー!\n");
        }
    }
};

// ===== Enemy (abstract) =====
class Enemy {
protected:
    int health;
    int attackPower;
public:
    Enemy(int hp, int atk) {
        health = hp;
        attackPower = atk;
    }
    virtual void move() = 0;
    virtual void attack(Player* player) = 0;
    virtual ~Enemy() {}

    void takeDamage(int dmg) {
        health -= dmg;
        printf("敵がダメージを受けた! 残りHP: %d\n", health);
    }
    bool isDefeated() { return health <= 0; }
};

// ===== StraightEnemy =====
class StraightEnemy : public Enemy {
private:
    float direction;
public:
    StraightEnemy(int hp, int atk, float dir)
        : Enemy(hp, atk) {
        direction = dir;
    }
    void move() override {
        printf("直進敵: 方向 %.1f で直進移動\n", direction);
    }
    void attack(Player* player) override {
        printf("直進敵の攻撃! ダメージ: %d\n", attackPower);
        player->takeDamage(attackPower);
    }
};

// ===== ChaseEnemy =====
class ChaseEnemy : public Enemy {
private:
    Player* target;
public:
    ChaseEnemy(int hp, int atk, Player* p)
        : Enemy(hp, atk) {
        target = p;
    }
    void move() override {
        printf("追尾敵: プレイヤーを追跡中\n");
    }
    void attack(Player* player) override {
        printf("追尾敵の攻撃! ダメージ: %d\n", attackPower);
        player->takeDamage(attackPower);
    }
};

// ===== ZigzagEnemy =====
class ZigzagEnemy : public Enemy {
private:
    float amplitude;
public:
    ZigzagEnemy(int hp, int atk, float amp)
        : Enemy(hp, atk) {
        amplitude = amp;
    }
    void move() override {
        printf("ジグザグ敵: 振幅 %.1f でジグザグ移動\n", amplitude);
    }
    void attack(Player* player) override {
        printf("ジグザグ敵の攻撃! ダメージ: %d\n", attackPower);
        player->takeDamage(attackPower);
    }
};

// ===== Stage =====
class Stage {
private:
    int stageNumber;
    Enemy* enemies[3];
    int enemyCount;
public:
    Stage(int num) {
        stageNumber = num;
        enemyCount = 0;
    }
    void addEnemy(Enemy* e) {
        if (enemyCount < 3) {
            enemies[enemyCount++] = e;
        }
    }
    void start() {
        printf("\n===== ステージ %d 開始! =====\n", stageNumber);
    }
    void spawnEnemy() {
        printf("敵が %d 体出現!\n", enemyCount);
        for (int i = 0; i < enemyCount; i++) {
            enemies[i]->move();
        }
    }
    bool isCleared() {
        for (int i = 0; i < enemyCount; i++) {
            if (!enemies[i]->isDefeated()) return false;
        }
        return true;
    }
    Enemy** getEnemies() { return enemies; }
    int getEnemyCount() { return enemyCount; }
};

// ===== Main =====
int main() {
    system("chcp 65001 > nul");

    // プレイヤー生成
    Player* player = new Player(10, 3, 5.0f);

    // ステージ1生成
    Stage* stage = new Stage(1);

    // 敵を追加
    stage->addEnemy(new StraightEnemy(5, 1, 90.0f));
    stage->addEnemy(new ChaseEnemy(8, 2, player));
    stage->addEnemy(new ZigzagEnemy(6, 1, 2.5f));

    // ゲーム開始
    stage->start();
    stage->spawnEnemy();

    printf("\n--- 戦闘開始 ---\n");

    // プレイヤーが弾を発射
    Bullet* bullet = player->shoot();
    bullet->move();

    // 敵を攻撃
    Enemy** enemies = stage->getEnemies();
    for (int i = 0; i < stage->getEnemyCount(); i++) {
        bullet->hitCheck();
        enemies[i]->takeDamage(player->getAttackPower());
    }

    // 敵の攻撃
    printf("\n--- 敵の反撃 ---\n");
    enemies[0]->attack(player);

    // パワーアップアイテム取得
    printf("\n--- アイテム取得 ---\n");
    PowerUpItem* item = new PowerUpItem(2, "AttackUp");
    item->spawn();
    player->collectItem(item);

    // ステージクリア確認
    printf("\nステージクリア: %s\n", stage->isCleared() ? "YES" : "NO");

    // メモリ解放
    delete bullet;
    delete item;
    for (int i = 0; i < stage->getEnemyCount(); i++) {
        delete enemies[i];
    }
    delete stage;
    delete player;

    return 0;
}
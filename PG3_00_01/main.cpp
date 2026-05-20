#include <stdio.h>
#include <cstdlib>
#include <Windows.h>
#include <time.h>

// コールバック関数の型定義
typedef void(*Callback)(int dice, int guess);

// ----------------------
// サイコロを振る関数（純粋なロジック）
// ----------------------
int rollDice()
{
    return rand() % 6 + 1;
}

// ----------------------
// 結果表示＆判定（コールバック関数）
// ----------------------
void showResult(int dice, int guess)
{
    printf("サイコロの目 : %d\n", dice);

    int result = dice % 2; // 0=偶数, 1=奇数

    if (result == 0)
        printf("偶数です\n");
    else
        printf("奇数です\n");

    // 課題要件：「正解」「不正解」の表示
    if (result == guess)
        printf("正解！\n");
    else
        printf("不正解\n");
}

// ----------------------
// ゲームの進行管理（コールバックを使用）
// ----------------------
void playGame(Callback callback, int guess)
{
    printf("サイコロを振ります");

    // 課題要件：3秒待機
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        Sleep(1000); // 1秒ずつ待機
    }
    printf("\n");

    // 課題要件：ランダムに抽選
    int dice = rollDice();

    // 課題要件：コールバック関数で判定・表示
    callback(dice, guess);
}

int main()
{
    system("chcp 65001 > nul");
    srand((unsigned int)time(NULL));

    int guess;
    int again = 1;

    // 課題要件：関数ポインタ（コールバック）
    Callback cb = showResult;

    while (again == 1)
    {
        printf("========== サイコロゲーム ==========\n");
        printf("0 = 偶数\n");
        printf("1 = 奇数\n");

        // 課題要件：ユーザー入力＋バリデーション
        while (1)
        {
            printf("予想を入力してください (0=偶数 / 1=奇数) : ");
            scanf_s("%d", &guess);

            if (guess == 0 || guess == 1)
                break;

            printf("無効な入力です！0か1を入力してください。\n");
        }

        // ゲーム開始（コールバック渡し）
        playGame(cb, guess);

        printf("\nもう一度遊びますか？ (1=はい / 2=いいえ) : ");
        scanf_s("%d", &again);
        printf("\n");
    }

    printf("ゲーム終了\n");
    return 0;
}
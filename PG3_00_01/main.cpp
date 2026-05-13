#include <stdio.h>
#include <cstdlib>
#include <Windows.h>
#include <time.h>

// コールバック関数用の関数ポインタ
typedef void(*Callback)(int, int);

// 判定用コールバック関数
void showResult(int dice, int guess)
{
    printf("Dice : %d\n", dice);

    // 0 = Even
    // 1 = Odd
    int result = dice % 2;

    if (result == 0)
    {
        printf("偶数\n");
    }
    else
    {
        printf("奇数\n");
    }

    if (result == guess)
    {
        printf("正解!\n");
    }
    else
    {
        printf("不正解!\n");
    }
}

// サイコロを振る関数
void rollDice(Callback callback, int guess)
{
    int dice = rand() % 6 + 1;

    printf("サイコロを振ります");

    for (int i = 0; i < 3; i++)
    {
        printf(".");
        Sleep(1000);
    }

    printf("\n");

    // コールバック関数を呼び出す
    callback(dice, guess);
}

int main()
{
    system("chcp 65001 > nul");

    // 乱数初期化は1回だけ
    srand((unsigned int)time(NULL));

    int guess;
    int again = 1;

    while (again == 1)
    {
        printf("========== Dice Game ==========\n");
        printf("Guess Even or Odd\n");
        printf("0 = Even\n");
        printf("1 = Odd\n");

        // 正しい入力が来るまで繰り返す
        while (1)
        {
            printf("Your guess: ");
            scanf_s("%d", &guess);

            if (guess == 0 || guess == 1)
            {
                break;
            }

            printf("無効な入力です!\n");
        }

        // 関数ポインタ経由でコールバック実行
        rollDice(showResult, guess);

        printf("\nもう一度試しますか？\n");
        printf("1 = はい\n");
        printf("2 = いいえ\n");
        scanf_s("%d", &again);

        printf("\n");
    }

    printf("ゲーム終了\n");

    return 0;
}
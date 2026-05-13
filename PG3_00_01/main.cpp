#include <stdio.h>
#include <cstdlib>
#include <Windows.h>
#include <time.h>

// 関数ポインタ型
typedef void(*Callback)(int, int);

// コールバック関数
void showResult(int dice, int guess)
{
    printf("Dice : %d\n", dice);

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

// サイコロ関数
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

    // コールバック実行
    callback(dice, guess);
}

int main()
{
    system("chcp 65001 > nul");

    srand((unsigned int)time(NULL));

    int guess;
    int again = 1;

    // 関数ポインタ変数
    Callback cb = showResult;

    while (again == 1)
    {
        printf("========== Dice Game ==========\n");
        printf("0 = Even\n");
        printf("1 = Odd\n");

        while (1)
        {
            printf("Your guess : ");
            scanf_s("%d", &guess);

            if (guess == 0 || guess == 1)
            {
                break;
            }

            printf("無効な入力です!\n");
        }

        // 関数ポインタ経由
        rollDice(cb, guess);

        printf("\nもう一度遊びますか？\n");
        printf("1 = Yes\n");
        printf("2 = No\n");
        scanf_s("%d", &again);

        printf("\n");
    }

    printf("ゲーム終了\n");

    return 0;
}
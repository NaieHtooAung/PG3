#include <stdio.h>
#include <cstdlib>
#include <Windows.h>
#include <functional>
#include <time.h>

// [条件3・5] SetTimeout関数（ラムダにしない・通常関数として定義）
void SetTimeout(std::function<void()> callback, int milliseconds) {
    Sleep(milliseconds);
    callback();
}

int main() {
    system("chcp 65001 > nul");

    srand((unsigned int)time(NULL));

    // サイコロ（1〜6）
    int dice = (rand() % 6) + 1;

    printf("=== サイコロ 奇数・偶数ゲーム ===\n");
    printf("サイコロを振りました！\n");
    printf("奇数(1) か 偶数(2) を入力してください: ");

    int input;
    scanf_s("%d", &input);

    // [条件4] ラムダ式でdiceとinputをキャプチャーして判定関数を作成
    auto judge = [dice, input]() {
        printf("\nサイコロの目は【%d】でした！\n", dice);

        bool isOdd = (dice % 2 != 0);
        bool userChoseOdd = (input == 1);

        if (isOdd == userChoseOdd) {
            printf("正解！おめでとうございます！\n");
        }
        else {
            printf("残念！ハズレです...\n");
        }
        };

    printf("\n結果を確認中");
    // ドット演出
    for (int i = 0; i < 3; i++) {
        Sleep(800);
        printf(".");
        fflush(stdout);
    }
    printf("\n");

    // [条件3] SetTimeoutで3秒後に結果表示（judgeラムダを渡す）
    SetTimeout(judge, 3000);

    return 0;
}
#include <stdio.h>
#include <Windows.h>


// 再帰：n時間目の時給を求める
int hourlyWage(int t) {
    if (t == 1) {
        return 100;
    }
    return hourlyWage(t - 1) * 2 - 50;
}

// 再帰：合計賃金を求める
int totalSalary(int t) {
    if (t == 1) {
        return 100;
    }
    return totalSalary(t - 1) + hourlyWage(t);
}

int main()
{
    int choice = 0;
    int time = 0;
    int result = 0;

    SetConsoleOutputCP(65001);

    char str[] = "働く時間を入力してください:";
    printf("%s", str);
    scanf_s("%d", &time);
    char str2[] = "一般的な賃金体系は1番 / 再帰的な賃金は2番 を選んでください: ";
    printf("%s", str2);
    scanf_s("%d", &choice);

    if (choice == 1)
    {
        result = time * 1072;
       
        printf("あなたの賃金は %d 円です\n", result);
    }
    else if (choice == 2)
    {
        result = totalSalary(time);
        printf("あなたの賃金は %d 円です\n", result);
    }
    else
    {
        printf("無効な入力です\n");
    }

    return 0;
}
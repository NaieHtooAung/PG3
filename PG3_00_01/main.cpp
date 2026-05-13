#include <stdio.h>
#include <Windows.h>

// n時間目の時給
int hourlyWage(int t)
{
    if (t == 1) {
        return 100;
    }

    return hourlyWage(t - 1) * 2 - 50;
}

// 合計賃金
int totalSalary(int t)
{
    if (t == 1) {
        return hourlyWage(1);
    }

    return totalSalary(t - 1) + hourlyWage(t);
}

int main()
{
    SetConsoleOutputCP(65001);

    int time;
    int choice;

    printf("働く時間を入力してください: ");
    scanf_s("%d", &time);

    printf("一般的な賃金体系は1番 / 再帰的な賃金は2番 を選んでください: ");
    scanf_s("%d", &choice);

    int result = 0;

    if (choice == 1)
    {
        result = time * 1072;
    }
    else if (choice == 2)
    {
        result = totalSalary(time);
    }
    else
    {
        printf("無効な入力です\n");
        return 0;
    }

    printf("あなたの賃金は %d 円です\n", result);

    return 0;
}
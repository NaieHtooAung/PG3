#include <stdio.h>
#include <Windows.h>

// n時間目の時給を求める再帰関数
int hourlyWage(int t)
{
    // 1時間目
    if (t <= 1)
    {
        return 100;
    }

    // 前回時給 × 2 - 50
    return hourlyWage(t - 1) * 2 - 50;
}

// 合計賃金を求める再帰関数
int totalSalary(int t)
{
    // 1時間目
    if (t <= 1)
    {
        return 100;
    }

    // 前回までの合計 + 今回の時給
    return totalSalary(t - 1) + hourlyWage(t);
}

int main()
{
    system("chcp 65001 > nul");

    int time;

    printf("働く時間を入力してください: ");
    scanf_s("%d", &time);

    // 一般的な賃金体系
    int normalSalary = time * 1072;

    // 再帰的な賃金体系
    int recursiveSalary = totalSalary(time);

    printf("\n===== 計算結果 =====\n");

    printf("一般的な賃金体系 : %d 円\n", normalSalary);

    printf("再帰的な賃金体系 : %d 円\n", recursiveSalary);

    // 比較
    if (normalSalary > recursiveSalary)
    {
        printf("一般的な賃金体系の方が高いです\n");
    }
    else if (normalSalary < recursiveSalary)
    {
        printf("再帰的な賃金体系の方が高いです\n");
    }
    else
    {
        printf("どちらも同じ金額です\n");
    }

    return 0;
}
#include <stdio.h>
#include <Windows.h>

// n時間目の時給
int hourlyWage(int t)
{
    if (t == 1)
    {
        return 100;
    }

    return hourlyWage(t - 1) * 2 - 50;
}

// 合計賃金
int totalSalary(int t)
{
    if (t == 1)
    {
        return hourlyWage(1);
    }

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

    printf("\n--- 計算結果 ---\n");

    printf("一般的な賃金体系: %d 円\n", normalSalary);

    printf("再帰的な賃金体系: %d 円\n", recursiveSalary);

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
        printf("同じ金額です\n");
    }

    return 0;
}
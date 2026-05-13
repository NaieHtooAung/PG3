#include <stdio.h>
#include <Windows.h>

// 関数テンプレート
template <typename T>
T Min(T a, T b)
{
    return (a < b) ? a : b;
}

// char型の特殊化
template <>
char Min<char>(char a, char b)
{
    printf("数字以外は代入できません\n");
    return 0;
}

int main()
{
    system("chcp 65001 > nul");

    // int型
    int i1 = 5;
    int i2 = 3;
    printf("int : %d\n", Min(i1, i2));

    // float型
    float f1 = 2.5f;
    float f2 = 1.2f;
    printf("float : %.2f\n", Min(f1, f2));

    // double型
    double d1 = 6.5;
    double d2 = 4.5;
    printf("double : %.2lf\n", Min(d1, d2));

    // char型
    char c1 = 'A';
    char c2 = 'B';
    printf("char : %c\n", Min(c1, c2));

    return 0;
}
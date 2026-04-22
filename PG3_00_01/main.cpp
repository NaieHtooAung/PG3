#include <stdio.h>
#include <Windows.h>

template <typename Type>
Type Min(Type a, Type b)
{
    return (a > b) ? b : a;
}

template <>
char Min<char>(char a, char b)
{
    printf("数字以外は代入できません\n");
    return (a < b) ? a : b;
}

int main()
{
    SetConsoleOutputCP(65001);

    // int
    int a = 5, b = 3;
    printf("int: %d\n", Min(a, b));

    // float
    float x = 2.5f, y = 1.2f;
    printf("float: %.2f\n", Min(x, y));

    // double
    double d1 = 6.5, d2 = 4.5;
    printf("double: %.2lf\n", Min(d1, d2));

    // char
    char c1 = 'A', c2 = 'B';
	char result = Min(c1, c2);
    printf("char: %c\n", result);

    return 0;
}
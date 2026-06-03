#include <stdio.h>
#include <windows.h>

template<typename T>
T Min(T a, T b) {
    if (a < b) {
        return a;
    }
    else {
        return b;  // a >= b の場合は b を返す
    }
}

template<> char Min<char>(char a, char b) {
    printf("数字以外は代入出来ません");
    return 0;
}

int main(void) {
    SetConsoleOutputCP(65001);
    char chr1 = 'a';
    char chr2 = 'b';

    printf("%d\n", Min<int>(200, 500));
    printf("%f\n", Min<float>(1.0f, 3.0f));
    printf("%f\n", Min<double>(100.333, 80.333));
    Min<char>(chr1, chr2);

    return 0;
}
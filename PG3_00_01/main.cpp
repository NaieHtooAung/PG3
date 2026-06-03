#include <stdio.h>
#include <iostream>

int min_int(int x, int y) {
    return x < y ? x : y;
}

float min_float(float x, float y) {
    return x < y ? x : y;
}

double min_double(double x, double y) {
    return x < y ? x : y;
}

void min_char(char x, char y) {                          // ← void に変更
    std::cout << "数字以外は代入できません" << std::endl; // ← cout で出力
}

int main(void) {
    system("chcp 65001 > nul");
    int    x_int = 114, y_int = 514;
    float  x_float = 514.0f, y_float = 1140.0f;
    double x_double = 810.0, y_double = 1919.0;
    char   x_char = 'a', y_char = 'i';

    printf("%d\n", min_int(x_int, y_int));
    printf("%f\n", min_float(x_float, y_float));
    printf("%lf\n", min_double(x_double, y_double));
    min_char(x_char, y_char);                            // ← 戻り値を受け取らない

    return 0;
}
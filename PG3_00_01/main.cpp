#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/* int同士の比較 */
int Min_int_int(int a, int b) {
    return (a < b) ? a : b;
}

/* float同士の比較 */
float Min_float_float(float a, float b) {
    return (a < b) ? a : b;
}

/* double同士の比較 */
double Min_double_double(double a, double b) {
    return (a < b) ? a : b;
}

/* int と float の比較 */
double Min_int_float(int a, float b) {
    return (a < b) ? (double)a : (double)b;
}

/* int と double の比較 */
double Min_int_double(int a, double b) {
    return (a < b) ? (double)a : b;
}

/* float と double の比較 */
double Min_float_double(float a, double b) {
    return (a < b) ? (double)a : b;
}

int main() {
    system("chcp 65001 > nul");

    /* ① int, int */
    printf("[int,    int]    Min(3, 5)       = %d\n", Min_int_int(3, 5));

    /* ② float, float */
    printf("[float,  float]  Min(1.5, 2.5)   = %.1f\n", Min_float_float(1.5f, 2.5f));

    /* ③ double, double */
    printf("[double, double] Min(4.2, 3.8)   = %.1f\n", Min_double_double(4.2, 3.8));

    /* ④ int, float */
    printf("[int,    float]  Min(2, 1.5)     = %.1f\n", Min_int_float(2, 1.5f));

    /* ⑤ int, double */
    printf("[int,    double] Min(4, 3.9)     = %.1f\n", Min_int_double(4, 3.9));

    /* ⑥ float, double */
    printf("[float,  double] Min(2.5, 2.4)   = %.1f\n", Min_float_double(2.5f, 2.4));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/* クラステンプレートの定義 */
template <typename T1, typename T2>
class Min {
public:
    double calc(T1 a, T2 b) {
        return (a < b) ? (double)a : (double)b;
    }
};

int main() {
    system("chcp 65001 > nul");

    /* ① int, int */
    Min<int, int> m1;
    printf("[int,    int]    Min(3, 5)       = %.0f\n", m1.calc(3, 5));

    /* ② float, float */
    Min<float, float> m2;
    printf("[float,  float]  Min(1.5, 2.5)   = %.1f\n", m2.calc(1.5f, 2.5f));

    /* ③ double, double */
    Min<double, double> m3;
    printf("[double, double] Min(4.2, 3.8)   = %.1f\n", m3.calc(4.2, 3.8));

    /* ④ int, float */
    Min<int, float> m4;
    printf("[int,    float]  Min(2, 1.5)     = %.1f\n", m4.calc(2, 1.5f));

    /* ⑤ int, double */
    Min<int, double> m5;
    printf("[int,    double] Min(4, 3.9)     = %.1f\n", m5.calc(4, 3.9));

    /* ⑥ float, double */
    Min<float, double> m6;
    printf("[float,  double] Min(2.5, 2.4)   = %.1f\n", m6.calc(2.5f, 2.4));

    return 0;
}
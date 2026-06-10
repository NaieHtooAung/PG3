#include <stdio.h>
#include <cstdlib>
#include <Windows.h>
#include <cmath>

// 抽象クラス IShape
class IShape {
public:
    virtual void Size() = 0;  // 純粋仮想関数
    virtual void Draw() = 0;  // 純粋仮想関数
    virtual ~IShape() {}
};

// 円クラス
class Circle : public IShape {
private:
    double radius;  // 半径
public:
    Circle(double r) : radius(r) {}

    void Size() override {
        double area = M_PI * radius * radius;
        printf("円の面積: %.2f\n", area);
    }

    void Draw() override {
        printf("図形: 円、半径: %.2f\n", radius);
    }
};

// 矩形クラス
class Rectangle : public IShape {
private:
    double width;   // 幅
    double height;  // 高さ
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void Size() override {
        double area = width * height;
        printf("矩形の面積: %.2f\n", area);
    }

    void Draw() override {
        printf("図形: 矩形、幅: %.2f、高さ: %.2f\n", width, height);
    }
};

int main()
{
    system("chcp 65001 > nul");

    IShape* shapes[2];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    for (int i = 0; i < 2; i++) {
        shapes[i]->Draw();
        shapes[i]->Size();
        printf("\n");
    }

    // メモリ解放
    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }

    return 0;
}
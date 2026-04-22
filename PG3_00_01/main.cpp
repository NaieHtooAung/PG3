#include<stdio.h>
#include <cstdlib>
#include <Windows.h>
template <typename Type>
	Type Min (Type a, Type b)
	{
		if (a > b)
		{
			return Type(b);
		}
		else {
			return Type(a);
		}
	}
int main()
{
	SetConsoleOutputCP(65001);
	int a = 0;
	int b = 0;
	int choice = 0;
	float x = 0.0f;
	float y = 0.0f;
	printf_s("if it's int type 1 or float type 2\n");
	scanf_s("%d",&choice);
	if (choice == 1)
	{
		printf_s("input 2 int numbers\n");
		if (scanf_s("%d %d", &a, &b) == 2)
		{
			printf_s("minimum(a,b)=%d\n", Min(a, b));
		}
		else
		{
			printf_s("数字以外代入できません");
			return 1;
		}
	}
	if (choice == 2)
	{
		printf_s("input 2 float numbers\n");
		while (getchar() != '\n');
		if (scanf_s("%f %f", &x, &y) == 2)
		{
			printf_s("minimum(x,y)=%.2f\n", Min(x, y));
		}
		else
		{
			printf_s("数字以外代入できません");
			return 1;
		}
	}
	
	
	
	return 0;
}
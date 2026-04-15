#include<stdio.h>
#include <cstdlib>
#include <Windows.h>
int main()
{
	SetConsoleOutputCP(65001);
	char str[] = "こんにちは";
		printf("%s", str);

	return 0;
}
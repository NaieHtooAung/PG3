#include<stdio.h>
#include <cstdlib>
#include <Windows.h>
int main()
{
	system("chcp 65001 > nul");
	char str[] = "こんにちは";
		printf("%s", str);

	return 0;
}
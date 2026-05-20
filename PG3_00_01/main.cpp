#include <stdio.h>

template <typename T>

T Min(T a, T b)
{
	if (a < b)
	{
		return a;
	}
}

template<>
char Min<char>(char a, char b)
{
	printf("数字以外は代入出来ません");

	return 0;
}

int main(void)
{
	char chr1 = 'a';
	char chr2 = 'b';

	printf("%d\n", Min<int>(200, 500));
	printf("%f\n", Min<float>(1.0f, 3.0f));
	printf("%f\n", Min<double>(100.333, 80.333));
	Min<char>(chr1, chr2);

	return 0;
}
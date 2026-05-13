#include<stdio.h>
#include <cstdlib>
#include <Windows.h>
#include <time.h>

typedef void(*Callback)(int, int);

void showResult(int dice, int guess)
{

	printf("Dice: %d, Guess: %d\n", dice, guess);

	if (dice % 2 ==0)
	{
		printf("奇数\n");
	}
	if (dice % 2 != 0)
	{
		printf("偶数\n");
	}
	if ((dice % 2) == guess)
	{
		printf("正解\n");
	}
	if ((dice % 2) != guess)
	{
		printf("不正解\n");
	}
}

void rollDice(Callback callback, int guess)
{
	int dice = rand() % 6 + 1;
	printf("サイコロを振ります");

	for (int i = 0; i < 3; i++)
	{
		printf(".");
		Sleep(1000);
	}
	printf("\n");

	callback(dice, guess);
}

int main()
{
	system("chcp 65001 > nul");

	int guess;
	int again;
	again = 1;
	while (again == 1)
	{
		srand((unsigned int)time(NULL));
		printf("========== Dice Game ==========\n");
		printf("Guess Even or Odd\n");
		printf("0 = Even\n");
		printf("1 = Odd\n");
		printf("Your guess: ");
		scanf_s("%d", &guess);


		if (guess != 0 && guess != 1)
		{
			printf("無効な入力です!\n");
			srand((unsigned int)time(NULL));
			printf("========== Dice Game ==========\n");
			printf("Guess Even or Odd\n");
			printf("0 = Even\n");
			printf("1 = Odd\n");
			printf("Your guess: ");
			scanf_s("%d", &guess);
		}

		rollDice(showResult, guess);

		printf("もう一度試してみますか？\n");
		printf("１は　はい、2は　いいえ\n");
		scanf_s("%d", &again);
	}
	
	
	if (again != 1)
	{
		printf("終わり\n");
	}

	return 0;
}
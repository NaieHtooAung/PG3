#include<stdio.h>
#include <cstdlib>
#include <Windows.h>
#include<list>
#include<string>
using namespace std;
void printList(const list<const char*>& lst)
{
 for(const char* station : lst)
	{
	 printf("%s\n", station);
	}
}
int main()
{
	system("chcp 65001 > nul");
	list<const char*> stationList = {
		"Shinagawa",
		"Osaki",
		"Gotanda",
		"Meguro",
		"Ebisu",
		"Shibuya",
		"Harajuku",
		"Yoyogi",
		"Shinjuku",
		"Shin-Okubo",
		"Takadanobaba",
		"Mejiro",
		"Ikebukuro",
		"Otsuka",
		"Sugamo",
		"Komagome",
		"Tabata",
		"Nippori",
		"Uguisudani",
		"Ueno",
		"Okachimachi",
		"Akihabara",
		"Kanda",
		"Tokyo",
		"Yurakucho",
		"Shimbashi",
		"Hamamatsucho",
		"Tamachi"

	};
	printf("1970年の山手線駅の名前\n\n");
	printList(stationList);
	printf("\n");
	printf("2019年の山手線駅の名前\n");
	auto it = stationList.begin();
	for ( ;it != stationList.end(); ++it)
	{
		if (*it == "Nippori")
		{
			it++;
			break;
		}
	}
	stationList.insert(it, "Nishi-Nippori");
	printList(stationList);
	printf("\n");

	auto it2 = stationList.begin();
	for (; it2 != stationList.end(); ++it2)
	{
		if (*it2 == "Shinagawa") {
			it2++;
			break;
		}
	}
	printf("2022年の山手線駅の名前\n");
	stationList.insert(it2, "Takanawa Gateway");
	printList(stationList);


	return 0;
}
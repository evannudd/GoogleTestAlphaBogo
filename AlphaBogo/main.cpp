#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

int main()
{
	Game game;
	std::vector<int> list = { 3,2,1 };
	list = game.bogoSort(list);

	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i] << std::endl;
	}
	cin.get();
	return 0;
}
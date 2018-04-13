#include "Game.h"
#include <random>
#include <algorithm>

Game::Game()
{
}


Game::~Game()
{
}

void Game::start()
{
	isRunning = true;
}

std::vector<int> Game::bogoSort(std::vector<int> list)
{
	std::vector<int> gameList = list;
	while (!std::is_sorted(gameList.begin(), gameList.end()) ){
		gameList = sort(gameList);
	}

	return gameList;
}

std::vector<int> Game::sort(std::vector<int> list)
{
	std::vector<int> orderedList;

	while (!list.empty()) {
		int randomEleIndex = rand() % list.size();
		orderedList.push_back(list[randomEleIndex]);

		// remove random ele from list
		list.erase(list.begin() + randomEleIndex);
	}

	return orderedList;
}

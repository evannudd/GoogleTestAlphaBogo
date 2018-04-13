#include "Game.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <ctime>

Game::Game()
{
}


Game::~Game()
{
}

void Game::start()
{
	isRunning = true;

	// populate the game list with random ints.
	for (int i = 0; i < 10; i++) {
		myList.push_back(rand() % 100);
	}
}

void Game::run()
{
	// populate the game list and start isRunning.
	start();

	// display the list.
	for (int i = 0; i < myList.size(); i++) {
		std::cout << myList[i];
	}

	// Time how long it takes for the user to solve it.
	std::time_t time_now = time(0);
	userSort();
	std:time_t time_after = time(0);
	std::time_t totalUserTime = time_after - time_now;
	
	// time how long it takes for AlphaBogo to solve it.
	std::time_t time_now1 = time(0);
	bogoSort(myList);
	std::time_t time_after1 = time(0);
	std::time_t totalBogoTime = time_after1 - time_now1;
}

std::vector<int> Game::userSort() {
	std::vector<int> inputs;
	for (int i = 0; i < myList.size(); i++) {
		int newNumber;

		std::cout << "Entry [" << i << "] = ";
		std::cin >> newNumber;
		inputs.push_back(newNumber);
	}

	return inputs;
}

bool isSorted(std::vector<int> list) {
	return (std::is_sorted(list.begin(), list.end()));
}

std::vector<int> Game::bogoSort(std::vector<int> list)
{
	std::vector<int> gameList = list;
	while (!isSorted(gameList) ){
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

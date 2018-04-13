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
	std::cout << "[ ";
	for (int i = 0; i < myList.size(); i++) {
		std::cout << myList[i] << ", ";
	}
	std::cout << "]";

	// Time how long it takes for the user to solve it.
	std::time_t time_now = time(0);
	userSort();
	std:time_t time_after = time(0);
	std::time_t totalUserTime = time_after - time_now;
	
	std::cout << "Now the computer will try to sort it... this could take forever." << std::endl;
	// time how long it takes for AlphaBogo to solve it.
	std::time_t time_now1 = time(0);
	bogoSort(myList);
	std::time_t time_after1 = time(0);
	std::time_t totalBogoTime = time_after1 - time_now1;

	if (totalUserTime < totalBogoTime) {
		std::cout << "User did it faster!" << std::endl;
	}
	else {
		std::cout << "Robo did it faster!" << std::endl;
	}
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

bool Game::isSorted(std::vector<int> list) {
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
	std::vector<int> copyList = list;
	std::vector<int> orderedList;

	while (!copyList.empty()) {
		int randomEleIndex = rand() % copyList.size();
		orderedList.push_back(copyList[randomEleIndex]);

		// remove random ele from list
		copyList.erase(copyList.begin() + randomEleIndex);
	}

	return orderedList;
}

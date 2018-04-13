#pragma once
#include <vector>

class Game
{
private:
	bool isRunning = false;
	std::vector<int> myList;

public:
	Game();
	~Game();

	void start();
	void run();

	bool isSorted(std::vector<int> list);
	std::vector<int> userSort();
	std::vector<int> bogoSort(std::vector<int> list);
	std::vector<int> sort(std::vector<int> list);
};


#pragma once
#include <vector>

class Game
{
private:
	bool isRunning = false;

public:
	Game();
	~Game();

	void start();

	std::vector<int> bogoSort(std::vector<int> list);
	std::vector<int> sort(std::vector<int> list);
};


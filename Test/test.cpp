#include "pch.h"
#include "../AlphaBogo/Game.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(ListSort, AscendingInts) {
	Game game;
	
	std::vector<int> list = { 0,9,8,7,6,5,4,3,2,1 };
	std::vector<int> sorted = game.bogoSort(list);

	for (int i = 1; i < sorted.size(); i++) {
		int ele0 = sorted[i];
		int ele1 = sorted[i - 1];
		EXPECT_LE(ele1, ele0);
	}
}

TEST(ListSort, IsSorted)
{
	Game game;

	std::vector<int> list = { 0,1,2,3,4,5,6,7,8,9 };

	ASSERT_TRUE(game.isSorted(list));

}

TEST(ListSort, UserFirst)
{
	Game game;

	std::time_t userTime = 4;
	std::time_t bogoTime = 7;

	std::string fasterTime = game.getFasterTime(bogoTime, userTime);

	ASSERT_EQ(fasterTime, "User did it faster!");

}

TEST(ListSort, BogoFirst)
{
	Game game;

	std::time_t userTime = 7;
	std::time_t bogoTime = 4;

	std::string fasterTime = game.getFasterTime(bogoTime, userTime);

	ASSERT_EQ(fasterTime, "Robo did it faster!");

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
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

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
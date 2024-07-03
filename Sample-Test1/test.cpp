#include "pch.h"
#include "../Project11/baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game("123");
	void assertIlegalArgumnet(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e){

		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIlegalArgumnet("12");
	assertIlegalArgumnet("12s");
	assertIlegalArgumnet("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}


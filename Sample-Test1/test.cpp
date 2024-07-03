#include "pch.h"
#include "../Project11/baseball.cpp"

class BaseballFixture : public testing::Test {
public:
	Baseball game;
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
}



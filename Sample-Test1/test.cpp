#include "pch.h"
#include "../Project11/baseball.cpp"

TEST(BasballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}



#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {
	}

	bool isDuplicateNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be 3 letters");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicateNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}


	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		if (guessNumber == question) {
			return { true, 3, 0 };
		}

		int strikes = 0;
		int balls = 0;

		for (int ball_no = 0; ball_no < 3; ball_no++) {
			int question_no = question[ball_no];
			int guess_no = guessNumber[ball_no];

			if (question_no == guess_no) {
				strikes++;
				continue;
			}

			if (question.find(guess_no) != string::npos) {
				balls++;
				continue;
			}
		}

		return {false, strikes, balls };
	}

private:
	string question;
};
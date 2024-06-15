#include <iostream>
#include <vector>
#include <utility> // pair 헤더
#include <algorithm>
#include <string>
using namespace std;

vector <pair<char, int>> cards(5);

int colors[128] = { 0 };
int numbers[10] = { 0 };
char c;
int num, high = 0;


bool isStraight() {
	int stack = 0;
	for (int num : numbers) {
		if (num > 0) stack++;
		else stack = 0;

		if (stack == 5) return true;
	}

	return false;
}

bool isFlush() {
	return colors['R'] == 5 || colors['G'] == 5 || colors['B'] == 5 || colors['Y'] == 5;
}

string getStreak() {
	int kind = 0, same = 0;
	for (int i = 0; i < 10; i++) {
		if (numbers[i] > 0) {
			kind++;
			same = same < numbers[i] ? numbers[i] : same;
		}
		
	}

	if (same == 4) return "four card";
	if (same == 3 && kind == 2) return "full house";
	if (same == 3) return "triple card";
	if (same == 2 && kind == 3) return "two pair";
	if (same == 2 && kind == 4) return "one pair";

	return "Nan";
}
int getHigh() {
	for (int i = 9; i > 1; i--) {
		if (numbers[i] > 0) return i;
	}

	return -1;
}

int calc_pair(string made) {

	std::vector<std::vector<int>> vectorArray(5);

	for (int i = 0; i < 10; i++) {
		if (numbers[i] > 1) vectorArray[numbers[i]].push_back(i);
	}

	if (made == "four card")		return vectorArray[4][0];											// four card
	if (made == "full house")		return vectorArray[3][0] * 10 + vectorArray[2][0];						// full house
	if (made == "triple card")		return vectorArray[3][0];											// triple
	if (made == "two pair")			return max(vectorArray[2][0], vectorArray[2][1])*10 + min(vectorArray[2][0], vectorArray[2][1]);		// two pair
	if (made == "one pair")			return vectorArray[2][0];												// pair

	return -1;
}

int calc_score() {

	bool straight = isStraight();
	bool flush = isFlush();
	string streak = getStreak();
	int high = getHigh();

	if (isStraight() && isFlush())	return 900 + high;		// straight flush
	if (streak == "four card")		return 800 + calc_pair("four card");		// four card
	if (streak == "full house")		return 700 + calc_pair("full house");		// full house
	if (isFlush())					return 600 + high;		// flush
	if (isStraight())				return 500 + high;		// straight
	if (streak == "triple card")	return 400 + calc_pair("triple card");		// triple
	if (streak == "two pair")		return 300 + calc_pair("two pair");		// two pair
	if (streak == "one pair")		return 200 + calc_pair("one pair");		// pair

	return 100 + high;										// top
}

int main(void) {

	for (int i = 0; i < 5; i++) {
		cin >> c >> num;
		colors[c]++; numbers[num]++;
	}

	cout << calc_score() << '\n';

	return 0;
}

//B 3
//B 7
//R 1
//B 2
//Y 7
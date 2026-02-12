#include <iostream>
#include <vector>
#include <string>

#define COGS 8
#define GEARS 4

#define ROT_NUM 8

using namespace std;

vector<string> gear_series(GEARS);

void rotate_gear(int gear_No, int clockWise) {
	
	char right = gear_series[gear_No][2], left = gear_series[gear_No][6];

	if (clockWise > 0) rotate_right(gear_No);
	else rotate_left(gear_No);

	left_transmit(gear_No - 1, left, ROT_NUM - 6, clockWise);
	right_transmit(gear_No + 1, right, ROT_NUM - 2, clockWise);
	
	
}

void rotate_left(int gear_No) {
	gear_series[gear_No] = gear_series[gear_No].substr(1, COGS) + gear_series[gear_No][0];
}

void rotate_right(int gear_No) {
	gear_series[gear_No] = gear_series[gear_No][7] + gear_series[gear_No].substr(1, COGS);
}

void left_transmit(int gear_No, char c, int idx, int clockWise) {
	if (inRange(gear_No) && (c != gear_series[gear_No][idx]) ) {
		rotate_gear(gear_No, -clockWise);
	}
}

void right_transmit(int gear_No, char c, int idx, int clockWise) {
	if (inRange(gear_No) && (c != gear_series[gear_No][idx])) {
		rotate_gear(gear_No, -clockWise);
	}
}

bool inRange(int gear_No) {
	return 0 <= gear_No && gear_No < GEARS;
}
int calc_score() {
	int score = 0;
	char c;
	for (int i = 0; i < GEARS; i++) {
		c = gear_series[i][0];
		score += c - '0';

	}

	return score;
}

int main(void) {

	
	string input;
	for (int i = 0; i < GEARS; i++) {
		cin >> input;
		gear_series.push_back(input);
		
	}

	/*for (int i = 0; i < 4; i++) {
	cout << gear_series[i].front() << '\n';
}*/

	int K; cin >> K;

	int gear_No, direction;
	for (int i = 0; i < K; i++) {
		cin >> gear_No >> direction;

		rotate_gear(gear_No, direction);
	}

	cout << calc_score() << '\n';

	return 0;
}
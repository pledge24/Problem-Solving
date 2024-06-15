#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isFelindrom(int N) {
	
	string str, str_reversed;
	str = str_reversed = to_string(N);
	
	reverse(str_reversed.begin(), str_reversed.end());

	if (str == str_reversed) return true;

	return false;
}

bool isPrime(int N) {

	if (N == 1) return false;

	for (int i = 2; i <= N / 2; i++) {
		if (N % i == 0) return false;
	}

	return true;
}

int main1(void) {

	int N;

	cin >> N;

	while (1) {
		if (isFelindrom(N) && isPrime(N)) break;
		N++;
	}

	cout << N << '\n';

	return 0;
}
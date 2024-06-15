#include <iostream>
#include <vector>			// vector 
#include <cmath>			// ceil()

#define MAXN 1000000

using namespace std;

int main(void) {

	int N;
	vector<int> v(MAXN);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	int B, C;
	cin >> B >> C;

	// 항상 int 범위를 생각하자.
	long long main_inspector = N;			
	long long sub_inspector = 0;
	for (int i = 0; i < N; i++) {
		v[i] -= B;

		if (v[i] > 0) sub_inspector += ceil((double)v[i] / C); 
	}

	cout << main_inspector + sub_inspector << '\n';

	return 0;
}


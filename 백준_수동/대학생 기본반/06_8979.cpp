// 2023-10-17

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAXN 1001
using namespace std;

struct Country {
	int countryNumber;
	int goldMedals;
	int silverMedals;
	int bronzeMedals;
	int rank;
};

// 나라 정보를 비교하는 함수 (금메달 -> 은메달 -> 동메달 기준으로 내림차순 정렬)
bool compareCountries(const Country& a, const Country& b) {
	if (a.goldMedals != b.goldMedals) {
		return a.goldMedals > b.goldMedals;
	}
	else if (a.silverMedals != b.silverMedals) {
		return a.silverMedals > b.silverMedals;
	}
	else {
		return a.bronzeMedals > b.bronzeMedals;
	}
}

int main8979() {
	fastio;
	int N, K;
	cin >> N >> K;

	vector<Country> countries(N);

	// 나라 정보 입력 받기
	for (int i = 0; i < N; i++) {
		cin >> countries[i].countryNumber >> countries[i].goldMedals >> countries[i].silverMedals >> countries[i].bronzeMedals;
	}

	sort(countries.begin(), countries.end(), compareCountries);

	int current_rank = 1;

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			countries[0].rank = current_rank;
			current_rank++;
		}
		else {
			if (countries[i - 1].goldMedals == countries[i].goldMedals && countries[i - 1].silverMedals == countries[i].silverMedals && countries[i - 1].bronzeMedals == countries[i].bronzeMedals) {
				countries[i].rank = current_rank;
			}
			else {
				current_rank = i + 1;
				countries[i].rank = current_rank;
			}
		}

			
		
	}
	//// 정렬된 나라 정보 출력
	//for (const Country& country : countries) {
	//	std::cout << country.countryNumber << " " << country.goldMedals << " " << country.silverMedals << " " << country.bronzeMedals << std::endl;
	//}

	for (int i = 0; i < N; i++) {
		if (countries[i].countryNumber == K) {
			cout << countries[i].rank << '\n';
			return 0 ;
		}
	}
	
	return 0;
}
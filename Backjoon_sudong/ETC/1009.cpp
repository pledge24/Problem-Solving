#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void startTest(){
	int a, b; cin >> a >> b;

	int ans = a % 10;
	for(int i = 0; i < b-1; i++){
		ans *= a;
		ans %= 10;
	}

	if(ans == 0) ans = 10;
	cout << ans << '\n';
	return;
}

int main(void){
	fastio;

	int T; cin >> T;
	for(int t = 0; t < T; t++){
		startTest();
	}

	return 0;
}
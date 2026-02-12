#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    long long N; cin >> N;
    vector<int> dp = {0, 1, 0, 1, 1, 1, 1};

    string ans = dp[N % 7] ? "SK" : "CY";

    cout << ans <<'\n';
}
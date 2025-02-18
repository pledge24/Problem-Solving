#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
  
    string ans = N % 2 ? "CY" : "SK";

    cout << ans <<'\n';
}
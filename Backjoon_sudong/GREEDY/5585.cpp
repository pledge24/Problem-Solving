#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int money; cin >> money;
    int left = 1000 - money;

    vector<int> coins = {500, 100, 50, 10, 5, 1};

    int ans = 0;
    for(int elem : coins){
        while(elem <= left){
            left -= elem;
            ans++;
        }
    }

    cout << ans << '\n';
    
}
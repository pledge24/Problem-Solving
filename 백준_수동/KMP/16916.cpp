#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int myFind(string s){

}

int main() {
	fastio;
    
    string S, P; cin >> S >> P;

    int ans = S.find(P) != string::npos ? 1 : 0;

    cout << ans << '\n';
    
}
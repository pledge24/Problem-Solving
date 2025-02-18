#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// // n*(n+1) / 2
// long long upperBound(long long S){
    
//    long long n = sqrt(S);

//     while(n*(n+1) / 2 <= S){
//         n++;
//     }

//     return n; 
// }

int main() {
	fastio;
    long long S; cin >> S;

    long long num = 1;
    long long ans = 0;
    while(S - num > num){
        //cout << S << " " << num << '\n';
        S -= num;
        num++;
        ans++;
    }

    cout << ans + 1 << '\n';
}
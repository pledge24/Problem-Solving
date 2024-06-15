#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    long long cur_zeros = 0, cur_ones = 1;
    long long temp_zeros, temp_ones;
    for(int i = 2; i <= N; i++){
        temp_zeros = cur_zeros + cur_ones;
        temp_ones = cur_zeros;

        cur_zeros = temp_zeros;
        cur_ones = temp_ones;
    }
    
    cout << cur_zeros + cur_ones << '\n';
}
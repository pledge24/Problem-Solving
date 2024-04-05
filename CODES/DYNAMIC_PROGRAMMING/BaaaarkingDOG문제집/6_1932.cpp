#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    vector<vector<int>> v1(N);
    vector<vector<int>> sum(N);

    int num;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            cin >> num;
            v1[i].push_back(num);
            sum[i].push_back(num);
        }
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) {
                sum[i][j] += sum[i-1][j];
                continue;
            }
            if(j == i) {
                sum[i][j] += sum[i-1][j-1];
                continue;
            }

            sum[i][j] += max(sum[i-1][j], sum[i-1][j-1]);
        }
    }

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j <= i; j++){
    //         cout << sum[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << *max_element(sum[N-1].begin(), sum[N-1].end()) << '\n';

}
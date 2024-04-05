#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N, M; cin >> N >> M;

    vector<int> v1(N+1);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }
    
    int min_H = 0;
    int max_H = *max_element(v1.begin(), v1.end());
    int H = (min_H + max_H)/2;
    long long best_M = LLONG_MAX;
    int best_H = H;

    while(min_H <= max_H){
        long long curr_M = 0;
        for(int i = 0; i < N; i++){
            curr_M += (v1[i] - H) > 0 ? v1[i] - H : 0;
        }

        if(curr_M > M){             // 통나무가 초과로 잘린 경우
            min_H = H + 1;
            if(best_M - M > curr_M - M){
                best_M = curr_M;
                best_H = H;
            }
        }
        else if(curr_M < M){        // 통나무가 미만으로 잘린 경우
            max_H = H - 1;
        }
        else{
            best_H = H;
            break;
        }

        H = (min_H + max_H)/2;
    }

    int ans = best_H;

    cout << ans << '\n';
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int T; cin >> T;

    for(int i = 0; i < T; i++){
        int N; cin >> N;

        vector<int> v_up(N+1);       
        for(int j = 1; j <= N; j++){
            cin >> v_up[j];
        }

        vector<int> v_down(N+1);
        for(int j = 1; j <= N; j++){
            cin >> v_down[j];
        }

        vector<int> sum_up(N+1);
        vector<int> sum_down(N+1);

        sum_up[1] = v_up[1], sum_up[2] = v_down[1] + v_up[2];
        sum_down[1] = v_down[1], sum_down[2] = v_up[1] + v_down[2];

         for(int j = 3; j <= N; j++){
            sum_up[j] = max(sum_down[j-1], sum_down[j-2]) + v_up[j];
            sum_down[j] = max(sum_up[j-1], sum_up[j-2]) + v_down[j];
        }

        cout << max(sum_up[N], sum_down[N]) << '\n';
    }
    

}
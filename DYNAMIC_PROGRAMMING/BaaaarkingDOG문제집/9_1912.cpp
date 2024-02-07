#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    vector<int> v1(N+1);

    for(int i=1; i<=N; i++){
        cin >> v1[i];
    }
    
    vector<int> streak_O(N+1);
    vector<int> streak_x(N+1);

    streak_O[1] = streak_x[1] = v1[1];

    for(int i=2; i<=N; i++){
        streak_O[i] = max(streak_O[i-1] + v1[i], v1[i]);
        streak_x[i] = max(streak_x[i-1], streak_O[i-1]);

        //printf("i = %d, streak O : %d, streak X: %d\n", i, streak_O[i], streak_x[i]);
    }

    cout << max(streak_x[N], streak_O[N]) << '\n';
}
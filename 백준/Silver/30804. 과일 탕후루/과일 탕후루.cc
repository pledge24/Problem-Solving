#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    vector<int> v1;
    for(int i = 0; i < N; i++){
        int num; cin >> num;
        v1.push_back(num);
    }

    const int MaxNo = 9;
    int ans = 0;
    for(int i = 1; i <= MaxNo; i++){
        for(int j = i+1; j <= MaxNo; j++){

            int streak = 0;
            int maxStreak = 0;
            for(int elem : v1){
                if(elem == i || elem == j){
                    streak++;
                }
                else{
                    streak = 0;
                }

                maxStreak = max(maxStreak, streak);
            }
            ans = max(maxStreak, ans);
        }
    }

    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N, M; cin >> N >> M;
    vector<pair<int, string>> v1;
    for(int i = 0; i < N; i++){
        string str; int num; cin >> str >> num;
        v1.push_back(make_pair(num, str));
    }

    for(int i = 0; i < M; i++){
        int power; cin >> power;
        auto it = lower_bound(v1.begin(), v1.end(), power, 
            [](const pair<int, string>& a, int val) {
                return a.first < val;
            });

        cout << v1[it - v1.begin()].second << '\n';
    }

    return 0;
}
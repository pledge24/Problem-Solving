#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int cnt = 0;
int len = 0;

void Backtracking(vector<int>& v1, int& S, int sum, int idx){
    if(sum == S && len > 0){
        cnt++;
    }

    for(int i = idx; i < v1.size(); i++){
        len++;
        Backtracking(v1, S, sum + v1[i], i+1);
        len--;
    }

    return;
}

int main(void){
    fastio;
    int N, S; cin >> N >> S;

    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    Backtracking(v1, S, 0, 0);

    cout << cnt << '\n';

    return 0;
}
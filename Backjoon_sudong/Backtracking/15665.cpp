#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> sequece;
vector<int> prevSequece;

void Backtracking(vector<int>& v1, int& M, int cnt){
    if(cnt == M){

        if(prevSequece >= sequece)
            return; 

        for(int elem : sequece){
            cout << elem << ' ';
        }
        cout << '\n';

        prevSequece = sequece;

        return;
    }

    for(int i = 0; i < v1.size(); i++){
        sequece.push_back(v1[i]);
        Backtracking(v1, M, cnt+1);
        sequece.pop_back();
    }
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    sort(v1.begin(), v1.end());

    Backtracking(v1, M, 0);

    return 0;
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> sequence;
vector<int> prevSequence;

void Backtracking(vector<int>& v1, int& M, int idx, int cnt){
    if(cnt == M){
        if(sequence <= prevSequence)
            return;

        for(int elem : sequence){
            cout << elem << ' ';
        }
        cout << '\n';

        prevSequence = sequence;
        return;
    }

    for(int i = idx; i < v1.size(); i++){
        sequence.push_back(v1[i]);
        Backtracking(v1, M, i+1, cnt+1);
        sequence.pop_back();
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

    Backtracking(v1, M, 0, 0);

    return 0;
}
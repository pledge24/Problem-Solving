#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> seqence;
vector<int> prevSeqence;

void Backtracking(vector<int>& v1, int& M, int cnt){
    // cout << "test: " << idx << '\n';
    
    if(cnt == M){
        if(seqence == prevSeqence)
            return;       

        for(int elem : seqence){
            cout << elem << ' ';
        }
        cout << '\n';
        
        prevSeqence = seqence;

        return;
    }

    for(int i = 0; i < v1.size(); i++){      
        seqence.push_back(v1[i]);
        Backtracking(v1, M, cnt+1);
        seqence.pop_back();
    }

    return;
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    // input Data.
    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());

    int cnt = 0;
    Backtracking(v1, M, cnt);

    return 0;
}
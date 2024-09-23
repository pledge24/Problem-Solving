#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> v1; 

void dfs(int idx, int num, vector<int>& P){
    if(idx == 0) return;

    if(P[idx] == num){
        dfs(idx - 1, num - 1, P);
        cout << v1[idx] << " ";
    }
    else{
        dfs(idx - 1, num, P);
    }
}

int main() {
	fastio;
    int N; cin >> N;

    v1.resize(N+1);
    vector<int> dp(N+1), A(N+1), P(N+1); 
    
    int num, len = 0;
    for(int i = 1; i <= N; i++){
        cin >> num;
        v1[i] = num;

        auto idx = lower_bound(A.begin()+1, A.begin()+len+1, num);
        *idx = num;
        P[i] = distance(A.begin(), idx);
        if(idx == A.begin()+len+1){
            len++;
        }
    }

    cout << len << '\n';
    dfs(N, len, P);
}


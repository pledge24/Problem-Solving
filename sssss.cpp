#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M;

vector<int> v1;
vector<int> ans;

void dfs(int idx, int size){
    if(size == M){
        for(int elem: ans){
            cout << elem << ' ';
        }
        cout << '\n';
    }

    for(int i = idx; i < v1.size(); i++){
        if(!v1[i]) continue;
        
        ans.push_back(v1[i]);
        dfs(i + 1, size + 1);
        if(i > 0 && v1[i-1] == v1[i]){
            v1[i] == 0;
        }
        ans.pop_back();
    }
}

int main() {
	fastio;
    cin >> N >> M;

    v1.resize(N);
    
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    sort(v1.begin(), v1.end());

    dfs(0, 0); 
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M;

vector<int> v1, visited;

vector<int> ans;
void dfs(int idx){

    if(ans.size() == M){
        for(int elem: ans){
            cout << elem << ' ';
        }
        cout <<'\n';

        return;
    }

    for(int i=0; i<v1.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            ans.push_back(v1[i]);
            dfs(i+1);
            visited[i] = false;
            ans.pop_back();
        }
    }
    
        
    

    return;
}

int main() {
	fastio;
    cin >> N >> M;

    v1.resize(N);
    visited.resize(N);

    for(int i=0; i<N; i++){
        cin >> v1[i];
    }
    
    sort(v1.begin(), v1.end());
    
    dfs(0);

}
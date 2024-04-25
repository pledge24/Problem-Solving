#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
vector<int> child_n;

int dfs(int idx){
    
    child_n[idx] = 1;
    
    for(int adj : tree[idx]){
        if(!visited[adj]){
            visited[adj] = true;
            child_n[idx] += dfs(adj);
        }
        
    }
    
    return child_n[idx];
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    tree.resize(n+1);
    child_n.resize(n+1);
    visited.resize(n+1);
    
    for(vector<int> v1 : wires){
        tree[v1[0]].push_back(v1[1]);
        tree[v1[1]].push_back(v1[0]);
    }
    
    visited[1] = true;
    dfs(1);
    
    // for(int elem : child_n){
    //     cout << elem << ' ';
    // }
    // cout << '\n';
    
    for(int i = 2; i <= n; i++){
        child_n[i] = abs(child_n[i] - abs(child_n[i] - child_n[1]));
    }
    
//     for(int elem : child_n){
//         cout << elem << ' ';
//     }
    
    answer = *min_element(child_n.begin()+2, child_n.end());
    
    return answer;
}
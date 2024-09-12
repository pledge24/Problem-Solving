#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int K;
vector<vector<int>> dungeons_global;
vector<bool> visited;
vector<int> order;
int ans = 0;
void dfs(int size){
    
    if(size == dungeons_global.size()){
        int left_k = K;
        int cnt = 0;
        for(int elem : order){
            if(left_k < dungeons_global[elem][0]) break;
            
            cnt++;
            left_k -= dungeons_global[elem][1];
        }
        
        ans = max(ans, cnt);
        
        return;
    }
    
    for(int i = 0; i < dungeons_global.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            order.push_back(i);
            
            dfs(size+1);
            
            visited[i] = false;
            order.pop_back();
        }
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    K = k;
    int answer = -1;
    int dungeons_size = dungeons.size();
    visited.resize(dungeons_size);
    dungeons_global = dungeons;
        
    dfs(0);
    
    answer = ans;
    
    return answer;
}
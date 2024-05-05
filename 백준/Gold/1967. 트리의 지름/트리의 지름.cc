#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct weight_data
{
    int node_no;
    int weight;
};

vector<vector<weight_data>> nodes;

int N; 
int max_length = -1;

int dfs(int node_no){
  
    if(nodes[node_no].size() == 0) return 0;

    vector<int> length;
    
    for(weight_data next_node : nodes[node_no]){
        length.push_back(dfs(next_node.node_no) + next_node.weight);
    }
    sort(length.begin(), length.end(), greater<int>());

    if(length.size() >= 2){     
        max_length = max(max_length, length[0]+length[1]);
    }
   
    return length[0];
}
int main() {
	fastio;
    cin >> N;

    nodes.resize(N+1, vector<weight_data>());
   
    int node1, node2, weight;
    for(int i = 0; i < N-1; i++){
        cin >> node1 >> node2 >> weight;
        nodes[node1].push_back({node2, weight});
    }
   
    if(N == 1){
        cout << 0 << '\n';
        return 0;
    }

    vector<int> length;
    for(weight_data next_node : nodes[1]){
        length.push_back(dfs(next_node.node_no) + next_node.weight);
    }
    sort(length.begin(), length.end(), greater<int>());

    // for(int elem : length){
    //     cout << elem << ' ';
    // }
    // cout << '\n';

    if(length.size() >= 2){
        max_length = max(max_length, length[0]+length[1]);
    }
    else{
        max_length = max(max_length, length[0]);
    }


    cout << max_length << '\n';
}
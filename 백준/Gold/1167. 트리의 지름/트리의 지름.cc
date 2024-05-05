#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct weight_data
{
    int node_no;
    int weight;
};

vector<vector<weight_data>> nodes;
vector<bool> visited;

int N; 
int max_length = -1;

int dfs(int node_no){
  
    vector<int> length;   
    bool find = false;
    for(weight_data next_node : nodes[node_no]){
        if(!visited[next_node.node_no]){
            find = true;
            visited[next_node.node_no] = true;
            //cout << node_no << " " << next_node.node_no << '\n';
            length.push_back(dfs(next_node.node_no) + next_node.weight);
        }
        
    }

    if(!find) return 0;

    sort(length.begin(), length.end(), greater<int>());
    
    if(length.size() >= 2){    
        // cout << node_no << " " <<  length[0] << " " << length[1] << '\n';
        max_length = max(max_length, length[0]+length[1]);
    }
   
    return length[0];
}

bool cmp(const weight_data &a, const weight_data &b){
    return a.node_no < b.node_no;
}
int main() {
	fastio;
    cin >> N;

    nodes.resize(N+1);
    visited.resize(N+1);

    int node1, node2, weight;
    for(int i = 0; i < N; i++){
        cin >> node1;

        while(1){
            cin >> node2;
            if(node2 == -1) break;
            cin >> weight;
            nodes[node1].push_back({node2, weight});
            
        }     
        
        sort(nodes[node1].begin(), nodes[node1].end(), cmp);
    }
      
    // for(int i = 1; i <= N; i++){
    //     for(weight_data elem : nodes[i]){
    //         cout << elem.node_no << ' ';
    //     }
    //     cout << '\n';
    // }
    
    vector<int> length;
    visited[1] = true;
    for(weight_data next_node : nodes[1]){
        visited[next_node.node_no] = true;
        length.push_back(dfs(next_node.node_no) + next_node.weight);
    }
    sort(length.begin(), length.end(), greater<int>());

    // for(int elem : length){
    //     cout << elem << ' ';
    // }
    // cout << '\n';

    if(length.size() >= 2){
        //cout << 1 << " " <<  length[0] << " " << length[1] << '\n';
        max_length = max(max_length, length[0]+length[1]);
    }
    else{
        max_length = max(max_length, length[0]);
    }

    cout << max_length << '\n';
}
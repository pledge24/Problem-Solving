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

// 현재 노드를 루트로 하는 서브트리의 지름을 구해 가장 긴 지름과 비교 및 저장 후,
// 현재 노드에서 가장 긴 길이를 반환한다.
int dfs(int node_no){
  
    if(nodes[node_no].size() == 0) return 0;

    vector<int> length;
    
    for(weight_data next_node : nodes[node_no]){
        length.push_back(dfs(next_node.node_no) + next_node.weight);
    }  
    
    // 내림차순 정렬.
    sort(length.begin(), length.end(), greater<int>()); 

    if(length.size() >= 2){     
        max_length = max(max_length, length[0]+length[1]);
    }
   
    return length[0];
}

int main() {
	fastio;
    cin >> N;

    nodes.resize(N+1);
   
    // input data.
    int node1, node2, weight;
    for(int i = 0; i < N-1; i++){
        cin >> node1 >> node2 >> weight;
        nodes[node1].push_back({node2, weight});
    }
   
    // 노드 개수가 1인경우, 정답은 0.
    if(N == 1){
        cout << 0 << '\n';
        return 0;
    }

    vector<int> length;

    // 각각의 자식노드 서브트리에서 가장 긴 길이를 가져온다.
    // dfs를 통해 자식노드에서도 반복한다.
    for(weight_data next_node : nodes[1]){
        length.push_back(dfs(next_node.node_no) + next_node.weight);
    }

    // 내림차순 정렬.
    sort(length.begin(), length.end(), greater<int>());     

    // 지름의 길이가 저장된 가장 긴 길이랑 비교해 더 긴 길이를 저장한다.
    // 가져온 길이 중 1번째, 2번째로 긴 길이의 합을 지름의 길이로 결정한다.
    // 자식노드가 1개인 경우, 1번째 길이를 지름의 길이로 결정한다.
    if(length.size() >= 2){
        max_length = max(max_length, length[0]+length[1]);
    }
    else{
        max_length = max(max_length, length[0]);
    }


    cout << max_length << '\n';
}
#include <bits/stdc++.h>

struct Node{
    int parent = -1;
    std::vector<int> child;
};

using namespace std;
using Graph = vector<Node>;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    // 이름이랑 ID 매핑
    map<string, int> m1; // <판매원 이름, ID>
    m1["-"] = 0;
    int N = enroll.size();
    for(int i = 0; i < N; i++){
        const string& name = enroll[i];
        m1[name] = i+1;
    }
        
    // Generate Graph
    Graph graph(N+1);
    for(int i = 0; i < N; i++){
        const string& child = enroll[i];
        const string& parent = referral[i];
        
        int child_id = m1[child];
        int parent_id = m1[parent];
        
        graph[child_id].parent = parent_id;
        graph[parent_id].child.push_back(child_id);
    }

    answer.resize(N+1, 0);
    for(int i = 0; i < seller.size(); i++){
        string name = seller[i]; 
        int profit = 100 * amount[i];    
        int node_id = m1[name];
        
        while(node_id != -1){
            int fee = profit * 0.1;
            answer[node_id] += (profit - fee);
            
            // cout << "nodeId: " << node_id << " " << profit << " " << fee << '\n';
            
            profit = fee;
            node_id = graph[node_id].parent;
            
            // for(auto elem : answer)
            //     cout << elem << ' ';
            // cout << '\n';
        }
    }   
    
    answer.erase(answer.begin());
       
    return answer;
}
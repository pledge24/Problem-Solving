#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

map<string, string> parent;
map<string, int> node_rank;
map<string, int> network_size;

string find_root(string x) {
    if (x == parent[x]) return x;

    return parent[x] = find_root(parent[x]);
}

// https://www.acmicpc.net/problem/4195
int union_root(string name1, string name2) {
    
    if(parent[name1] == ""){
        parent[name1] = name1;
        network_size[name1] = 1;
    }

    if(parent[name2] == ""){
        parent[name2] = name2;
        network_size[name2] = 1;
    }

    name1 = find_root(name1);
    name2 = find_root(name2);
  
    if(name1 == name2) return network_size[name1];
    
    if (node_rank[name1] < node_rank[name2]){
        parent[name1] = name2;
    } 
    else if(node_rank[name1] > node_rank[name2]){
        parent[name2] = name1;
    } 
    else {
        parent[name1] = name2;
        node_rank[name1]++;
    }

    network_size[name1] += network_size[name2];
    network_size[name2] = network_size[name1];

    return network_size[name1];
}

void friendNetwork(){
    int F; cin >> F;
    parent.clear();
    node_rank.clear();
    network_size.clear();

    string name1, name2;
    for(int i = 0; i < F; i++){
        cin >> name1 >> name2;
        cout << union_root(name1, name2) << '\n';
    }
}

int main() {
	fastio;

    int T; cin >> T;

    for(int i = 0; i < T; i++){
        friendNetwork();
    }
}
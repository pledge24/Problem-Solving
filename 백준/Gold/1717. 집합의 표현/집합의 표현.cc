#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<int> parent, node_rank;

int find_root(int x) {
    if (x == parent[x]) return x;

    return parent[x] = find_root(parent[x]);
}

void union_root(int x, int y) {
    
    x = find_root(x);
    y = find_root(y);
 
    if(x == y) return;
  
    if (node_rank[x] < node_rank[y]) parent[x] = y;
    else if(node_rank[x] > node_rank[y]) parent[y] = x;
    else {
        parent[x] = y;
        node_rank[x]++;
    }
}

bool isSameSet(int x, int y){
    x = find_root(x);
    y = find_root(y);

    return x == y;
}

int main() {
	fastio;

    int n, m; cin >> n >> m;

    parent.resize(n+1);
    iota(parent.begin(), parent.end(), 0);

    node_rank.resize(n+1);

    int cmd, a, b;
    for(int i = 0; i < m; i++){
        cin >> cmd >> a >> b;

        if(cmd == 0){
            union_root(a, b);
        }
        else{
            string ans = isSameSet(a, b) ? "YES" : "NO";
            cout << ans << '\n';
        }
    }
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int n, m; cin >> n >> m;

    vector<vector<int>> graph(n+1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    set<int> s;
    for(int elem : graph[1]){
        s.insert(elem);
        for(int elem2 : graph[elem]){
            if(elem2 == 1)
                continue;
            
            s.insert(elem2);
        }
    }
        

    cout << s.size() << '\n';

    return 0;
}
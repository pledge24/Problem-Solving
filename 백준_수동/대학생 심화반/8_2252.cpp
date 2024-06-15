#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct nums{
    int order;
    int num;
};

struct cmp
{
    bool operator()(nums a, nums b) {
        if(a.order == b.order){
            return a.num > b.num;
        }
        return a.order < b.order;
    }
};

int main() {
	fastio;
    int N, M; cin >> N >> M;
    
    int a, b;
    vector<int> v1(N+1, INT32_MIN);
    vector<bool> visited(N+1);
    for(int i = 0; i < M; i++){
        cin >> a >> b;

        if(!visited[a] && !visited[b]){
            v1[a] = 2;
            v1[b] = 1;
        }
        else if(visited[a] && !visited[b]){
            v1[b] = v1[a] - 1;
        }
        else if(!visited[a] && visited[b]){
            v1[a] = v1[b] + 1;
        }
        else{
            if(v1[a] == v1[b]){
                v1[a] = v1[b] + 1;
            }
        }

        visited[a] = visited[b] = true;
    }

    priority_queue<nums, vector<nums>, cmp> pq;
    for(int i = 1; i <= N; i++){
        pq.push({v1[i], i});
    }

    while (!pq.empty()) {
        nums ns = pq.top(); pq.pop();
        //printf("num: %d order: %d\n", ns.num, ns.order);
        cout << ns.num << ' ';
    }
    cout << '\n';

}
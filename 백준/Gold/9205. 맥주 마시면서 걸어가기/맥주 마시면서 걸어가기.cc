#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Pos = pair<int, int> ;

int Distance(Pos& pos1, Pos& pos2){
    return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
}

bool bfs(Pos& src, Pos& dst, vector<Pos>& v1){

    int N = v1.size();

    queue<Pos> q;
    vector<bool> visited(N);

    q.push(src);

    while(!q.empty()){
        Pos curPos = q.front(); q.pop();

        if(Distance(dst, curPos) <= 20*50)
            return true;

        for(int i = 0; i < N; i++){
            if(!visited[i] && (Distance(curPos, v1[i]) <= 20*50)){
                q.push(v1[i]);
                visited[i] = true;
            }
        }
    }

    return false;
}

void startTest(){
    int N; cin >> N;
    Pos src, dst;
    vector<Pos> v1;

    // 집
    {
        int x, y; cin >> x >> y;
        src = make_pair(x, y);
    }

    // 편의점 (N개)
    for(int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        v1.push_back(make_pair(x, y));
    }

    // 락 페스티벌
    {
        int x, y; cin >> x >> y;
        dst = make_pair(x, y);
    }

    bool canMove = bfs(src, dst, v1);

    string ans = canMove ? "happy" : "sad";
    cout << ans << '\n';
}

int main(void){
    fastio;
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;
}
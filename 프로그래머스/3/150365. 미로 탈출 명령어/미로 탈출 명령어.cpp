#include <bits/stdc++.h>

#define DIR 4

using namespace std;
using Pos = pair<int, int>;
using Matrix = vector<vector<string>>;

// 명령어 상하좌우(u, d, l, r) d -> l -> r -> u || 아래 -> 왼쪽 -> 오른쪽 -> 위
char cmd[DIR] = {'d', 'l', 'r', 'u'};
int dx[DIR] = {1, 0, 0, -1};
int dy[DIR] = {0, -1, 1, 0};

int N, M, K;
bool found = false;

bool inRange(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= M;
}

void DfsUtil(string& answer, Pos& curPos, Pos& endPos, vector<char>& path){
    int distance = abs(curPos.first - endPos.first) + abs(curPos.second - endPos.second);
    int remain = K - path.size();
    
    // 가지치기(1. 이미 찾은 경우, 2. 도착할 수 없는 경우, 3. 정확히 K번째에 도착할 수 없는 경우)
    if(found == true || remain < distance || abs(remain - distance) % 2 == 1)
        return;
    
    // 종료 조건
    if(path.size() == K){
        if(curPos == endPos){
            found = true;
            answer = string(path.begin(), path.end());
        }
        return;
    }
    
    for(int i = 0; i < DIR; i++){
        int nx = curPos.first + dx[i];
        int ny = curPos.second + dy[i];
        
        Pos curPos = make_pair(nx, ny);
        
        // 재방문 처리(visited)는 안 해도 됨.
        if(inRange(nx, ny)){
            path.push_back(cmd[i]);
            DfsUtil(answer, curPos, endPos, path);
            path.pop_back();
        }
    }
}

void Dfs(string& answer, Pos& startPos, Pos& endPos){
    
    vector<char> path;
    
    DfsUtil(answer, startPos, endPos, path);
    
    return;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "impossible";
    
    Pos startPos = make_pair(x, y);
    Pos endPos = make_pair(r, c);
    
    N = n; M = m; K = k;// 전역 변수로 돌려쓰자 걍
    
    // 이동 가능한 모든 칸에 대해 4방향 이동시 해당 칸 최소로 변경
    Dfs(answer, startPos, endPos);
    
    return answer;
}
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

#define INF 2000000000

using namespace std;
using Pos = pair<int, int>;

vector<int> solution(vector<vector<int>> city, vector<vector<int>> road) {
    // 1. 각 지점의 제한 속도 저장 및 가로/세로 도로 분류
    map<Pos, int> limits;
    vector<vector<Pos>> road_points(road.size());
    
    vector<vector<int>> H_roads; // {도로 인덱스, y, x1, x2}
    vector<vector<int>> V_roads; // {도로 인덱스, x, y1, y2}
    
    for (int i = 0; i < road.size(); i++) {
        int x1 = min(road[i][0], road[i][2]);
        int y1 = min(road[i][1], road[i][3]);
        int x2 = max(road[i][0], road[i][2]);
        int y2 = max(road[i][1], road[i][3]);
        int limit = road[i][4];
        
        // 양 끝점 추가
        road_points[i].push_back({x1, y1});
        road_points[i].push_back({x2, y2});
        
        // 카메라 (정중앙) 위치 추가 및 속도 갱신 (더 낮은 속도 우선)
        Pos mid = {(x1 + x2) / 2, (y1 + y2) / 2};
        road_points[i].push_back(mid);
        
        if (limits.find(mid) == limits.end()) limits[mid] = limit;
        else limits[mid] = min(limits[mid], limit);
        
        if (y1 == y2) H_roads.push_back({i, y1, x1, x2});
        else V_roads.push_back({i, x1, y1, y2});
    }
    
    // 2. 도시 좌표를 속해있는 도로의 정점에 추가
    for (auto& c : city) {
        int cx = c[0], cy = c[1];
        for (auto& hr : H_roads) {
            if (cy == hr[1] && hr[2] <= cx && cx <= hr[3]) {
                road_points[hr[0]].push_back({cx, cy});
            }
        }
        for (auto& vr : V_roads) {
            if (cx == vr[1] && vr[2] <= cy && cy <= vr[3]) {
                road_points[vr[0]].push_back({cx, cy});
            }
        }
    }
    
    // 3. 가로 도로와 세로 도로가 만나는 "교차점" 찾아 정점에 추가
    for (auto& hr : H_roads) {
        for (auto& vr : V_roads) {
            if (hr[2] <= vr[1] && vr[1] <= hr[3] && vr[2] <= hr[1] && hr[1] <= vr[3]) {
                road_points[hr[0]].push_back({vr[1], hr[1]});
                road_points[vr[0]].push_back({vr[1], hr[1]});
            }
        }
    }
    
    // 4. 각 도로 내부의 정점들을 정렬하여 인접한 점들끼리 간선(그래프) 연결
    map<Pos, vector<Pos>> graph;
    for (int i = 0; i < road.size(); i++) {
        auto& pts = road_points[i];
        sort(pts.begin(), pts.end());
        // 중복 좌표 제거
        pts.erase(unique(pts.begin(), pts.end()), pts.end());
        
        for (int j = 0; j < (int)pts.size() - 1; j++) {
            graph[pts[j]].push_back(pts[j+1]);
            graph[pts[j+1]].push_back(pts[j]);
        }
    }
    
    // 5. 올바른 다익스트라 수행 (최대 병목 경로 탐색)
    map<Pos, int> maxLimit;
    priority_queue<pair<int, Pos>> pq;
    
    Pos startPos = {city[0][0], city[0][1]};
    pq.push({INF, startPos});
    maxLimit[startPos] = INF;
    
    while (!pq.empty()) {
        int curLimit = pq.top().first;
        Pos u = pq.top().second;
        pq.pop();
        
        // 이미 큐에 있는 값보다 더 나은 경로로 방문된 적 있다면 스킵
        if (maxLimit[u] > curLimit) continue;
        
        for (Pos v : graph[u]) {
            int nextLimit = curLimit;
            if (limits.find(v) != limits.end()) {
                nextLimit = min(nextLimit, limits[v]);
            }
            
            // 더 높은 속도로 도달할 수 있을 때만 갱신 및 큐에 삽입
            if (maxLimit.find(v) == maxLimit.end() || nextLimit > maxLimit[v]) {
                maxLimit[v] = nextLimit;
                pq.push({nextLimit, v});
            }
        }
    }
    
    // 6. 결과 정리
    vector<int> answer;
    for (int i = 1; i < city.size(); i++) {
        Pos target = {city[i][0], city[i][1]};
        int res = maxLimit.count(target) ? maxLimit[target] : 0;
        if (res == INF) res = 0; // 카메라를 한 번도 거치지 않은 경우
        answer.push_back(res);
    }
    
    return answer;
}
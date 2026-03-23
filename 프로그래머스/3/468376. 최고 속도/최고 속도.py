import heapq
from collections import defaultdict

def solution(city, road):
    INF = 10**15
    limits = defaultdict(lambda: INF)
    
    H_roads = []
    V_roads = []
    # 각 도로(인덱스)에 속하는 핵심 지점(노드)들을 담을 집합
    road_points = [set() for _ in range(len(road))]
    
    # 1. 도로 양 끝점과 카메라(중앙점) 위치 추가 및 가로/세로 도로 분류
    for i, (x1, y1, x2, y2, lim) in enumerate(road):
        x1, x2 = min(x1, x2), max(x1, x2)
        y1, y2 = min(y1, y2), max(y1, y2)
        
        road_points[i].add((x1, y1))
        road_points[i].add((x2, y2))
        
        mid = ((x1 + x2) // 2, (y1 + y2) // 2)
        road_points[i].add(mid)
        # 같은 지점에 카메라가 여러 개일 경우 최소 제한 속도를 따름
        limits[mid] = min(limits[mid], lim)
        
        if y1 == y2:
            H_roads.append((i, y1, x1, x2))
        else:
            V_roads.append((i, x1, y1, y2))
            
    # 2. 도시 위치를 해당 도로에 추가
    for cx, cy in city:
        for i, y_h, x_h_min, x_h_max in H_roads:
            if cy == y_h and x_h_min <= cx <= x_h_max:
                road_points[i].add((cx, cy))
        for i, x_v, y_v_min, y_v_max in V_roads:
            if cx == x_v and y_v_min <= cy <= y_v_max:
                road_points[i].add((cx, cy))
                
    # 3. 가로-세로 도로의 교차점 찾기
    for i, y_h, x_h_min, x_h_max in H_roads:
        for j, x_v, y_v_min, y_v_max in V_roads:
            if x_h_min <= x_v <= x_h_max and y_v_min <= y_h <= y_v_max:
                road_points[i].add((x_v, y_h))
                road_points[j].add((x_v, y_h))
                
    # 4. 그래프 생성 (각 도로의 점들을 정렬하여 인접한 점끼리 간선 연결)
    graph = defaultdict(list)
    for i in range(len(road)):
        pts = sorted(list(road_points[i]))
        for k in range(len(pts) - 1):
            u, v = pts[k], pts[k+1]
            graph[u].append(v)
            graph[v].append(u)
            
    # 5. 다익스트라 (Maximum Bottleneck Path) 탐색
    start = tuple(city[0])
    max_speed = defaultdict(int)
    max_speed[start] = INF
    
    # 최대힙을 위해 음수 사용: (-유지 가능한 최고 속도, 현재 노드)
    pq = [(-INF, start)]
    
    while pq:
        curr_speed_neg, u = heapq.heappop(pq)
        curr_speed = -curr_speed_neg
        
        # 이미 더 나은 속도로 도달한 적이 있다면 스킵
        if curr_speed < max_speed[u]:
            continue
            
        for v in graph[u]:
            v_limit = limits[v]
            # 다음 노드로 이동할 때의 속도: 현재까지의 속도와 다음 위치 카메라 제한 속도 중 작은 값
            nxt_speed = min(curr_speed, v_limit)
            
            if nxt_speed > max_speed[v]:
                max_speed[v] = nxt_speed
                heapq.heappush(pq, (-nxt_speed, v))
                
    # 6. 결과 도출 (2번 도시부터 n번 도시까지)
    ans = []
    for k in range(1, len(city)):
        c = tuple(city[k])
        speed = max_speed[c]
        # 제한 속도 카메라를 한 번도 안 만난 경우 (무한대) 0 반환
        if speed == INF:
            ans.append(0)
        else:
            ans.append(speed)
            
    return ans
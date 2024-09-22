#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define point pair<long long, long long>
#define line pair<point, point>

using namespace std;

vector<line> lines;
vector<int> root;
vector<int> node_rank;

// first => x pos
// second => y pos
int ccw(point A, point B, point C) { 
    long long res = (B.first - A.first)*(C.second - A.second) - (C.first - A.first)*(B.second - A.second);

    return (res > 0) - (res < 0);
}

// pair의 대소비교는 어떻게 되는 것인가?
// pair를 안 쓰고 정답을 맞추는 방법은 뭐가 있을까?(곂치는 점 관련문제)
bool isCross(pair<point, point> l1, pair<point, point> l2) {

    point p1 = l1.first;
    point p2 = l1.second;
    point p3 = l2.first;
    point p4 = l2.second;

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); // l1 기준
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); // l2 기준

    // 두 직선이 일직선 상에 존재 + 벡터가 0인 경우 존재(같은 점 존재)
    if (p1p2 == 0 && p3p4 == 0) {

    	// 비교를 일반화하기 위한 점 위치 변경
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);
        
        return p3 <= p2 && p1 <= p4; // 두 선분이 포개어져 있는지 확인
    }
    
    return p1p2 <= 0 && p3p4 <= 0;
    
    
}

int find_root(int x) {
    if (x == root[x]) return x;

    return root[x] = find_root(root[x]);
}

void union_root(int x, int y) {
    
    x = find_root(x);
    y = find_root(y);
 
    if(x == y) return;
  
    if (node_rank[x] < node_rank[y]) root[x] = y;
    else if(node_rank[x] > node_rank[y]) root[y] = x;
    else {
        root[x] = y;
        node_rank[x]++;
    }
}

bool isSameSet(int x, int y){
    x = find_root(x);
    y = find_root(y);

    return x == y;
}

void solve(int idx){
    for(int i = 0; i < idx; i++){
        if(isCross(lines[i], lines[idx])){
            union_root(i, idx);
        }
    }
}

int main() {
	fastio;

    int N; cin >> N;

    lines.resize(N);
    root.resize(N);
    node_rank.resize(N);
    
    int x1, y1, x2, y2;
    for(int i = 0; i < N; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        point p1 = {x1, y1};
        point p2 = {x2, y2};

        root[i] = i;
        node_rank[i] = 1;
        lines[i] = {p1, p2};
        
        solve(i);
    }

    // 그룹의 개수와 가장 크기가 큰 그룹에 속한 선분의 개수를 구한다.
    map<int, int> m1;
    int maxCnt = -1;
    for(int i = 0; i < N; i++){
        int rootIdx = find_root(i);
        m1[rootIdx]++;
        maxCnt = max(maxCnt, m1[rootIdx]);
    }

    cout << m1.size() << '\n';
    cout << maxCnt << '\n';

    // int maxRank = *max_element(node_rank.begin(), node_rank.end());
    // int cnt = count(node_rank.begin(), node_rank.end(), maxRank);

    // cout << maxRank << '\n';
    // cout << cnt << '\n';
}


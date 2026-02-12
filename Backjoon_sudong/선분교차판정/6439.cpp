#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define point pair<long long, long long>

using namespace std;

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

void solve(){
    point p1, p2, p3, p4, p5, p6;

    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    cin >> p3.first >> p3.second >> p4.first >> p4.second;
    
    // cout << p3.first << " " << p3.second << " " 
    // << p4.first << " " << p4.second << '\n';

    p5 = {p3.first, p4.second};
    p6 = {p4.first, p3.second};

    pair<point, point> l1 = {p1, p2};
    vector<pair<point, point>> recLines = {{p3, p5}, {p5, p4}, {p4, p6}, {p6, p3}};
    
    bool condition1 = false;
    for(pair<point, point> line : recLines){
        point pp1 = line.first;
        point pp2 = line.second;
        if(isCross(l1, line)){
            condition1 = true;
            break;
        }
    }

    bool condition2 = false;

    long long minX = min(p1.first, p2.first);
    long long maxX = max(p1.first, p2.first);
    long long minY = min(p1.second, p2.second);
    long long maxY = max(p1.second, p2.second);

    long long recMinX = min(p3.first, p4.first);
    long long recMaxX = max(p3.first, p4.first);
    long long recMinY = min(p3.second, p4.second);
    long long recMaxY = max(p3.second, p4.second);

    if(recMinX <= minX && recMinY <= minY && recMaxX >= maxX && recMaxY >= maxY)
        condition2 = true;
    
    string ans = (condition1 || condition2) ? "T" : "F";

    cout << ans << '\n';
}

int main() {
	fastio;

    int T; cin >> T;

    for(int t = 0; t < T; t++){
        solve();
    }
}


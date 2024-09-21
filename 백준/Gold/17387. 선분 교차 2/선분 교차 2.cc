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

bool isIntersect(pair<point, point> l1, pair<point, point> l2) {

    point p1 = l1.first;
    point p2 = l1.second;
    point p3 = l2.first;
    point p4 = l2.second;

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); // l1 기준
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); // l2 기준

    // 두 직선이 일직선 상에 존재
    if (p1p2 == 0 && p3p4 == 0) {

    	// 비교를 일반화하기 위한 점 위치 변경
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);
        
        return p3 <= p2 && p1 <= p4; // 두 선분이 포개어져 있는지 확인
    }
    
    return p1p2 <= 0 && p3p4 <= 0;
    
}

int main() {
	fastio;

    point p1, p2, p3, p4;

    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    cin >> p3.first >> p3.second >> p4.first >> p4.second;
    
    pair<point, point> l1 = {p1, p2};
    pair<point, point> l2 = {p3, p4};

    int ans = isIntersect(l1, l2);
    
    cout << ans << '\n';
}
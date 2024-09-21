#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct Point{
    long long x;
    long long y;

    bool operator<(const Point& other) const {
        return std::tie(x, y) < std::tie(other.x, other.y);
    }
};

int ccw(Point A, Point B, Point C) { 
    long long res = (B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y);

    return (res > 0) - (res < 0);
}

bool isIntersect(pair<Point, Point> l1, pair<Point, Point> l2) {

    Point p1 = l1.first;
    Point p2 = l1.second;
    Point p3 = l2.first;
    Point p4 = l2.second;

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); // l1 기준
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); // l2 기준

    //cout << p1p2 << " " << p3p4 << '\n';

    // 두 직선이 일직선 상에 존재
    if (p1p2 == 0 && p3p4 == 0) {

        map<Point, int> m1;
        m1[p1]++; m1[p2]++; m1[p3]++; m1[p4]++;
        if(m1.size() < 4) return 1;

    	// 비교를 일반화하기 위한 점 위치 변경
        if (p1.x > p2.x) swap(p2, p1);
        if (p3.x > p4.x) swap(p3, p4);
        
        // return p3.x <= p2.x && p1.x <= p4.x; // 두 선분이 포개어져 있는지 확인
        return (p1.x <= p4.x && p1.y <= p4.y) && (p3.x <= p2.x && p3.y <= p2.y);
    }
    
    return p1p2 <= 0 && p3p4 <= 0;
    
}

int main() {
	fastio;
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;
    
    pair<Point, Point> l1 = {p1, p2};
    pair<Point, Point> l2 = {p3, p4};

    int ans = isIntersect(l1, l2);
    
    cout << ans << '\n';

    // cout <<ccw(p1, p2, p3)*ccw(p1, p2, p4) << " " << ccw(p3, p4, p1)*ccw(p3, p4, p2);
}
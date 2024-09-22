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

void calcCrossPoint(pair<point, point> l1, pair<point, point> l2){

    point p1 = l1.first;
    point p2 = l1.second;
    point p3 = l2.first;
    point p4 = l2.second;

    long long D = (p1.first - p2.first)*(p3.second - p4.second) - (p1.second - p2.second)*(p3.first - p4.first);
    
    long double x = (p1.first*p2.second - p1.second*p2.first)*(p3.first-p4.first) - (p1.first-p2.first)*(p3.first*p4.second - p3.second*p4.first);
    long double y = (p1.first*p2.second - p1.second*p2.first)*(p3.second-p4.second) - (p1.second-p2.second)*(p3.first*p4.second - p3.second*p4.first);
    

    if(D != 0){
        x = x/D == 0 ? 0 : x/D; 
        y = y/D == 0 ? 0 : y/D; 

        if(x != floor(x/D) || y != floor(y/D))
            cout.precision(10);
        
        cout << x << " " << y << '\n';
    }
    else{

        // cout << p1.first << " " << p1.second << '\n';
        // cout << p2.first << " " << p2.second << '\n';

        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);

        // cout << p1.first << " " << p1.second << '\n';
        // cout << p2.first << " " << p2.second << '\n';
        // cout << p3.first << " " << p3.second << '\n';
        // cout << p4.first << " " << p4.second << '\n';
              
        // cout << p2.first << " " << p2.second << '\n';
        // cout << p3.first << " " << p3.second << '\n';
        if(p2 == p3 || p4 == p1){
            point p = p2 == p3 ? p2 : p4;

            if(p.first != floor(p.first) || p.second != floor(p.second))
                cout.precision(10);
            cout << p.first << " " << p.second << '\n';
        }
    
        
    }
}

int main() {
	fastio;

    point p1, p2, p3, p4;

    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    cin >> p3.first >> p3.second >> p4.first >> p4.second;
    
    pair<point, point> l1 = {p1, p2};
    pair<point, point> l2 = {p3, p4};

    if(isCross(l1, l2)){
        cout << 1 << '\n';
        calcCrossPoint(l1, l2);
    }
    else{
        cout << 0 << '\n';
    }
    
    
}


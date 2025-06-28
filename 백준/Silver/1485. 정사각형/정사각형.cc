#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define X first
#define Y second

using namespace std;
using int64 = long long;
using Pos = pair<int64, int64>;
using Vec2D = pair<int64, int64>;

Vec2D subVec(Pos p1, Pos p2){
    return make_pair(p2.first - p1.first, p2.second - p1.second);
}

Vec2D addVec(Pos p1, Pos p2){
    return make_pair(p2.first + p1.first, p2.second + p1.second);
}

bool makeSquare(vector<Pos>& v1){

    // 정렬한다.
    sort(v1.begin(), v1.end());

    // 1) 왼쪽 아래의 점 하나를 잡는다.
    Pos p1 = v1[0];

    // 2) 나머지 점들로 향하는 벡터들을 구한다.
    Vec2D d1 = subVec(p1, v1[1]);
    Vec2D d2 = subVec(p1, v1[2]);
    Vec2D d3 = subVec(p1, v1[3]);

    // printf("d1: (%d %d)\n", d1.first, d1.second);
    // printf("d2: (%d %d)\n", d2.first, d2.second);
    // printf("d3: (%d %d)\n", d3.first, d3.second);

    // 정사각형 조건 1. d1, d2는 직교한다.
    if((d1.first*d2.first + d1.second*d2.second) != 0)
        return false;

    // 정사각형 조건 2. d1, d2는 크기가 같다.
    int64 ld1l = d1.first*d1.first + d1.second*d1.second;
    int64 ld2l = d2.first*d2.first + d2.second*d2.second;
    if(ld1l != ld2l)
        return false;

    // 정사각형 조건 3. 벡터의 합이 가장 멀리있는 벡터와 같다.
    if(addVec(d1, d2) != d3)
        return false;

    return true;
}

int main(void){
    fastio;
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        vector<Pos> v1;
        for(int j = 0; j < 4; j++){
            int x, y;
            cin >> x >> y;
            v1.push_back(make_pair(x, y));
        }

        int ans = makeSquare(v1);

        cout << ans << '\n';
    }



    return 0;
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<long long> vx, vy;

// 오늘의 교훈 10만*10만은 100억이기 때문에 int를 벗어난다
// long double이라는게 있다.
// 소수점 고정은 아래와 같이 사용한다.
// cout << fixed;
// cout.precision(1);

// 신발끈 공식 링크: https://namu.wiki/w/%EC%8B%A0%EB%B0%9C%EB%81%88%20%EA%B3%B5%EC%8B%9D
double getAreas(){
    long double res1 = 0.0;
    long double res2 = 0.0;

    for(int i = 0; i < vx.size(); i++){
       res1 += vx[i]*vy[(i+1)%vx.size()];
       res2 += vx[(i+1)%vx.size()]*vy[i];
    }

    return abs(res1-res2)/2;
}

int main() {
	fastio;

    long long N; cin >> N;

    vx.resize(N);
    vy.resize(N);

    long long x, y;
    for(int i = 0; i < N; i++){
        cin >> vx[i] >> vy[i];
    }

    long double ans = getAreas();

    cout << fixed;
    cout.precision(1);
    cout << ans << '\n';

}
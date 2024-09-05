#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<long long> vx, vy;

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
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define point pair<long long, long long>

using namespace std;

int ccw(point A, point B, point C) { 
    long long res = (B.first - A.first)*(C.second - A.second) - (C.first - A.first)*(B.second - A.second);

    return (res > 0) - (res < 0);
}

int main() {
	fastio;
    point p1, p2, p3;

    cin >> p1.first >> p1.second;
    cin >> p2.first >> p2.second;
    cin >> p3.first >> p3.second;

    int ans = ccw(p1, p2, p3);

    cout << ans << '\n';
}
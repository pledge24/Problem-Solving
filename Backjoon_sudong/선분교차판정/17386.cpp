#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    long double x1, y1, x2, y2; 
    cin >> x1 >> y1 >> x2 >> y2;

    long double x3, y3, x4, y4; 
    cin >> x3 >> y3 >> x4 >> y4;
    
    if((x1-x2)*(y3-y4) == (x3-x4)*(y1-y2)){
        cout << 0 << '\n';
        return 0;
    }

    // cout << "pass0" << '\n';

    long double m1 = (y2-y1)/(x2-x1);
    long double b1 = -m1*x1 + y1;

    long double m2 = (y4-y3)/(x4-x3);
    long double b2 = -m2*x3 + y3;

    long double px = (b2-b1)/(m1-m2);
    long double py = m1*(b2-b1)/(m1-m2)+b1;

    int ans = 0;
    if(min(x1, x2) <= px && px <= max(x1, x2) && min(y1, y2) <= py && py <= max(y1, y2)){
        // cout << "pass1" << '\n';
        if(min(x3, x4) <= px && px <= max(x3, x4) && min(y3, y4) <= py && py <= max(y3, y4)){
            ans = 1;
        }
    }

    cout << ans << '\n';
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;

    while(true){
        int x, y, z;
        cin >> x >> y >> z;
        if(x == 0 && y == 0 && z == 0)
            break;
        
        int maxNum = max({x, y, z});
        if(maxNum*2 >= x+y+z){
            cout << "Invalid" << '\n';
            continue;
        }

        map<int, int> m1;
        m1[x]++;
        m1[y]++;
        m1[z]++;

        string ans = "";
        switch (m1.size())
        {
        case 1:
            ans = "Equilateral";
            break;
        case 2:
            ans = "Isosceles";
            break;
        case 3:
            ans = "Scalene";
            break;
        }

        cout << ans << '\n';
    }
    return 0;
}
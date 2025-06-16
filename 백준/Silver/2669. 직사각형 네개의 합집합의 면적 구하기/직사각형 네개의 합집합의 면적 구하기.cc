#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Matrix = vector<vector<bool>>;

int main(void){
    fastio;
    Matrix matrix(100, vector<bool>(100));

    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int add = 0;
        for(int x = x1; x < x2; x++){
            for(int y = y1; y < y2; y++){
                if(matrix[x][y] == false){
                    matrix[x][y] = true;
                    add++;
                }
            }
        }

        cnt += add;
        // cout << "add: " << add << '\n';
        // cout << "(x1, y1) (x2, y2)" << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
    }

    cout << cnt << '\n';

    return 0;
}
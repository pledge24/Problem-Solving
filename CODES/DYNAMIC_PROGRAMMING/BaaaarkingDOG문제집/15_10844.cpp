#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIV 1000000000
using namespace std;

int main() {
	fastio;
    int N; cin >> N;

    vector<long long> v1{0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    for(int i=1; i<N; i++){
        vector<long long> v1_temp(10);
        v1_temp[0] = v1[1];
        v1_temp[1] = (v1[0] + v1[2]) % DIV;
        v1_temp[2] = (v1[1] + v1[3]) % DIV;
        v1_temp[3] = (v1[2] + v1[4]) % DIV;
        v1_temp[4] = (v1[3] + v1[5]) % DIV;
        v1_temp[5] = (v1[4] + v1[6]) % DIV;
        v1_temp[6] = (v1[5] + v1[7]) % DIV;
        v1_temp[7] = (v1[6] + v1[8]) % DIV;
        v1_temp[8] = (v1[7] + v1[9]) % DIV;
        v1_temp[9] = v1[8];

        v1 = v1_temp;
    }

    int cnt = 0;
    for(int elem: v1){
        cnt = (cnt + elem) % DIV;
        //printf("%d elem, cnt %d\n", elem , cnt);
    }

    cout << cnt << '\n';
    
}
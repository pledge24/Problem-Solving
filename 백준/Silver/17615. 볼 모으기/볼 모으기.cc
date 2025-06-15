#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    vector<char> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    int firstR = -1;
    int lastR = -1;
    int firstB = -1;
    int lastB = -1;
    int cntR = 0;
    int cntB = 0;
    for(int i = 0; i < N; i++){
        if(v1[i] == 'R'){
            cntR++;
            if(firstR == -1)
                firstR = i;
            
            lastR = i;
        }
        else{
            cntB++;
            if(firstB == -1)
                firstB = i;
            
            lastB = i;
        }
    }

    // printf("R: (%d %d), B: (%d %d)\n", firstR, lastR, firstL, lastL);

    // 1) R - 오른쪽 정렬
    int RR = cntB > 0 ? cntR - (N - 1 - lastB) : 0;
    // 2) R - 왼쪽 정렬
    int RL = cntB > 0 ? cntR - firstB : 0;

    // 1) B - 오른쪽 정렬
    int BR = cntR > 0 ? cntB - (N - 1 - lastR) : 0;
    // 2) B - 왼쪽 정렬
    int BL = cntR > 0 ? cntB - firstR : 0;

    // printf("R: (%d %d), B: (%d %d)\n", RR, RL, BR, BL);

    cout << min({RR, RL, BR, BL}) << '\n';

    return 0;
}
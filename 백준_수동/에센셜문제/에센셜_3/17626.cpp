#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int minCnt = INT32_MAX;
int debugCnt = 0;
void dfsUtil(int leftN, int cnt){
    if(leftN == 0){
        minCnt = min(minCnt, cnt);
        return;
    }

    if(leftN < 0){
        cout << "what?" << '\n';
        return;
    }

    int maxSqrt = sqrt(leftN);
    for(int i = maxSqrt; i >= 1; i--){
        int square = i*i;
        int tempLeftN = leftN - square;

        if(tempLeftN >= 0 && debugCnt <= 100){
            cout << tempLeftN << " " << i << '\n';
            dfsUtil(tempLeftN, cnt + 1);
            debugCnt++;

        }
    }

    return;
}

void dfs(int n){

    int maxSqrt = sqrt(n); cout << maxSqrt << '\n';
    for(int i = maxSqrt; i >= 1; i--){
        int square = i*i;
        int leftN = n - square;

        dfsUtil(leftN, 1);
    }

    return;
}

int main(void){
    fastio;
    int n; cin >> n;

    dfs(n);

    int ans = minCnt;

    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    vector<int> v1(N+1);

    for(int i=1; i<=N; i++){
        cin >> v1[i];
    }
    
    // N이 2이하이면 다 마시면 된다.
    if(N <= 2){
        int num = 0;
        for(int elem: v1){
            num += elem;
        }
        cout << num << '\n';
        return 0;
    }

    // N이 3이상인 경우
    vector<vector<int>> caseA(N+1, vector<int>(4));
    vector<vector<int>> caseB(N+1, vector<int>(4));

    caseA[2][1] = v1[1], caseA[2][2] = v1[2], caseA[2][3] = 0;
    caseB[2][1] = v1[1] + v1[2], caseB[2][2] = v1[1], caseB[2][1] = v1[2];

    for(int i=3; i<=N; i++){
        // caseA:마시는 경우
        caseA[i][1] = max(caseB[i-1][1], caseB[i-1][3]) + v1[i];
        caseA[i][2] = max(caseA[i-1][1], caseA[i-1][3]) + v1[i];
        caseA[i][3] = caseB[i-1][2] + v1[i];
        
        // caseB:마시지 않는 경우
        caseB[i][1] = caseA[i-1][2];
        caseB[i][2] = max(caseB[i-1][1], caseB[i-1][3]);
        caseB[i][3] = max(caseA[i-1][1], caseA[i-1][3]);
    }

    cout << max({caseA[N][1], caseA[N][2], caseA[N][3], caseB[N][1], caseB[N][2], caseB[N][3]}) << '\n';
}
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
    vector<vector<int>> caseA(N+1, vector<int>(5));

    caseA[2][1] = v1[1] + v1[2], caseA[2][2] = v1[1], caseA[2][3] = v1[2], caseA[2][4] = 0;
    

    for(int i=3; i<=N; i++){       
        caseA[i][1] = caseA[i-1][3] + v1[i];                            // OO
        caseA[i][2] = max(caseA[i-1][1], caseA[i-1][3]);                // OX
        caseA[i][3] = max(caseA[i-1][2], caseA[i-1][4]) + v1[i];        // XO
        caseA[i][4] = max(caseA[i-1][2], caseA[i-1][4]);                // XX
    }

    cout << *max_element(caseA[N].begin(), caseA[N].end()) << '\n';
}
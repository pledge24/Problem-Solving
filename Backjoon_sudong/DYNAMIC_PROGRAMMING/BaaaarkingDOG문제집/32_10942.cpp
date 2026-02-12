#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, E, S;
vector<int> v1;
vector<vector<int>> dp;

// bool inRange(int e, int s){
//     return s <= e && s <= S;
// }

int memorization(int e, int s){

    //cout << "{ " << e << " ," << s << " }" << '\n'; 
    // // 범위를 벗어나면 0
    // if(!inRange(e, s)){
    //     return 0;
    // }

    // 이미 저장된 값이면 해당 값 반환.
    if(dp[e][s] != -1){
        return dp[e][s];
    }

    //------- 저장된 값이 없는 경우 ---------

    int same_num = (int)(v1[e] == v1[s]);

    // 해당 길이가 2 이하인 경우 처음과 끝 수의 일치만 보고 반환.
    if(e-s <= 1){
        dp[e][s] = same_num;
        //cout << "(e, s): dp[e][s]: " << e << " " << s << " " << dp[e][s] << '\n'; 
        return dp[e][s];
    }
    
    // 해당 길이가 3 이상인 경우, 추가로 안에 펠린드롬이 있는지 확인.
    int sub_ans = memorization(e-1, s+1);
    
    dp[e][s] = (int)(same_num && memorization(e-1, s+1));
    return dp[e][s];
}

int main(void){
    fastio;
    cin >> N;

    v1.resize(N+1);
    dp.resize(N+1, vector<int>(N+1, -1));

    for(int i =1; i<=N; i++){
        cin >> v1[i];
    }

    
    // // 시간 초과;;
    // for(int e = 1; e <= N; e++ ){
    //     for(int s = 1; s <= e; s++){
    //         if(s == e) {
    //             dp[e][s] = true;
    //             continue;
    //         }

    //         if(v1[s] == v1[e]){
    //             if(e-s <= 2){
    //                 dp[e][s] = true;
    //                 continue;
    //             }

    //             dp[e][s] = dp[e-1][s+1] ? true : false;
    //         }
    //     }
    // }

    int M; cin >> M;
    int ans;
    for(int i=0; i<M; i++){
        cin >> S >> E;
        
        ans = memorization(E, S);
        
        cout << ans << '\n';
    }

    //print test.
    // for(int e = 1; e <= N; e++ ){
    //     for(int s = 1; s <= N; s++){
    //         cout << dp[e][s] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return 0;
}
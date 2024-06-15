#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M;

bool in_range(int idx){
    return 1 <= idx && idx <= N;
}

int main() {
	fastio;
    vector<bool> vip_arr(41);

    cin >> N >> M;

    // vip input
    int m;
    for(int i=0; i<M; i++){
        cin >> m;
        vip_arr[m] = true;
    }

    vector<int> case_swap(N+1);     // i번째에 좌석이 스왑된 경우의 수
    vector<int> case_noswap(N+1);   // i번째에 좌석이 스왑되지 않은 경우의 수

    case_swap[1] = 1, case_noswap[1] = 0;

    for(int idx =2; idx<=N; idx++){

        if(vip_arr[idx] || vip_arr[idx-1]){
            case_swap[idx] = case_swap[idx-1] + case_noswap[idx-1];
            case_noswap[idx] = 0;
        }
        else{
            case_swap[idx] = case_swap[idx-1] + case_noswap[idx-1];
            case_noswap[idx] = case_swap[idx-1];
        }
        
    }

    int ans = case_swap[N] + case_noswap[N];

    cout << ans << '\n';

    // for(int i = 1; i <=N; i++){
    //     cout << case_swap[i] << '\t';
    // }
    // cout << '\n';

    // for(int i = 1; i <=N; i++){
    //     cout << case_noswap[i] << '\t';
    // }
    // cout << '\n';
}
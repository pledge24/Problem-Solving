#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int isOver(vector<int>& v1, int mid, int N){
    int cnt = 0;
    for(int& elem : v1){
        cnt += elem / mid;
        if(cnt >= N)
            return true;
    }

    return false;
}

int binarySearch(vector<int>& v1, int N){
    int low = 0;
    int high = v1.back()+1;

    while(low < high){
        int mid = (low + high) / 2;
        if(mid == 0)
            break;

        if(isOver(v1, mid, N)){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }

    low = max(0, low-1);
    return low;
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;
    vector<int> v1(M);
    for(int i = 0; i < M; i++){
        cin >> v1[i];
    }

    sort(v1.begin(), v1.end());

    int ans = binarySearch(v1, N);

    cout << ans << '\n';

    return 0;
}
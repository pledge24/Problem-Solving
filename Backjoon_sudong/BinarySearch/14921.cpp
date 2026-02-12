#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;

    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    int start = 0;
    int end = v1.size() - 1;
    int ans = INT32_MAX;
    while(start < end){
        int res = v1[start] + v1[end];
            
        if(abs(res) < abs(ans))
            ans = res;

        if(ans == 0)
            break;

        if(res > 0){
            end--;
        }
        else{
            start++;
        }

    }

    cout << ans << '\n';

    return 0;
}
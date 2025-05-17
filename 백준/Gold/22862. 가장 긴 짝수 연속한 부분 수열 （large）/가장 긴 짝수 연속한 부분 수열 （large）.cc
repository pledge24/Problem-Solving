#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N, K; cin >> N >> K;

    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    int ans = 0;
    int oddN = 0;
    int end = 0;
    for(int start = 0; start <= end; start++){

        while(end < v1.size() && (oddN + (v1[end] % 2) <= K)){
            oddN += v1[end] % 2;

            end++;
        }

        // printf("%d %d %d\n", start, end, oddN);
        ans = max(ans, end-start-oddN);

        if(v1[start] % 2 == 1)
            oddN--;
    }

    cout << ans << '\n';

    return 0;   
}
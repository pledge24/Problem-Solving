#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int calcMinGap(vector<int>& v1, int M){
    int minGap = INT32_MAX;

    int end = 0;
    for(int start = 0; start <= end; start++){
        while(abs(v1[start] - v1[end]) < M && (end+1 < v1.size()))
            end++;

        // printf("start: %d, end: %d\n", start, end);
        int gap = abs(v1[start] - v1[end]);
        if(gap < M)
            continue;

        if(gap < minGap)
            minGap = gap;
    }
    return minGap;
}

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    vector<int> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    sort(v1.begin(), v1.end());

    int minGap = calcMinGap(v1, M);

    int ans = minGap;
    cout << ans << '\n';

    return 0;
}
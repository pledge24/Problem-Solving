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

    map<int, int> m1;

    int maxLen = 0;
    int end = 0;
    for(int start = 0; start <= end; start++){

        while(end < v1.size() && m1[v1[end]]+1 <= K){
            int curNum = v1[end];
            m1[curNum]++;
            // printf("end: %d, num: %d, count: %d\n", end, curNum, m1[curNum]);

            end++;
        }

        int len = end - start;
        // printf("start: %d, end: %d\n", start, end);
        maxLen = max(maxLen, len);

        m1[v1[start]]--;
    }

    cout << maxLen << '\n';

    return 0;
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// target이상의 부분 합의 최소 길이
int twoPointer(vector<int>& v1, int target){
    int end = 0; // start와 end는 겹쳐있다는 설정.
    int len = v1.size();
    int minLen = INT32_MAX, sum = v1[0];

    for(int start = 0; start < len; start++){

        // end 최대한 멀리 보내기
        while(end < len && sum < target){
            end++;
            if(end != len) sum += v1[end];
        }

        // 더 이상 S이상의 값이 없음.
        if(end == len) break;

        minLen = min(minLen, end-start+1);
        sum -= v1[start];
    }

    return minLen;
}

int main() {
	fastio;
    int N, S; cin >> N >> S;

    vector<int> v1; v1.resize(N);

    for(int i = 0; i < N; i++){
        cin >> v1[i];
    }

    int ans = twoPointer(v1, S);

    if(ans == INT32_MAX) ans = 0;

    cout << ans << '\n';
    
}
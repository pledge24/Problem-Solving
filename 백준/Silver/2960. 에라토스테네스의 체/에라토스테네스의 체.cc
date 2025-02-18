#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// 시간복잡도 O(N*log(logN))
int printPrimeNumbers(int num, int K){
    vector<int> arr(num+1);
    int cnt = 0;

    // 배열을 1부터 시작하는 값으로 채우기
    iota(arr.begin(), arr.end(), 1);

    for(int i = 2; i <= num; i++){
        if(arr[i] == 0) continue;

        for(int j = 1; i*j <= num; j++){
            int temp = i*j;
            if(arr[temp] == 0) continue;

            arr[temp] = 0;
            cnt++;
            if(cnt == K) return temp;
        }
    }

    return -1;
}

int main() {
	fastio;
    int N, K; cin >> N >> K;

    int ans = printPrimeNumbers(N, K);
    
    cout << ans << '\n';
}
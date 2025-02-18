#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;

    int N; cin >> N;
  
    // 왼쪽 -> 오른쪽 순으로 자리수가 커짐
    vector<int> digits(2000);
    digits[0] = 1;
    for(int n = 2; n <= N; n++){
        vector<int> calcRes(2000);

        // 각 자리수 곱하기
        for(int j = 0; j < digits.size(); j++){
            int num = digits[j]*n;

            int pos = j;
            while(num > 0){
                num += calcRes[pos];
                calcRes[pos] = num % 10;     // mod
                num /= 10;                  // carry
                pos++;
            }
        }

        for(int i = 0; i < digits.size(); i++){
            digits[i] = calcRes[i];
        }

        // for(int i = 0; i < 10; i++){
        //     cout << digits[i] << ' ';
        // }
        // cout << '\n';
    }

    int cnt = 0;
    int idx = 0;

    while(digits[idx] == 0){
        idx++;
        cnt++;
    } 

    cout << cnt << '\n';

    return 0;
}

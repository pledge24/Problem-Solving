#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;

    int N; cin >> N;
  
    // 왼쪽 -> 오른쪽 순으로 자리수가 커짐
    vector<int> digits(2000);
    vector<int> calcRes(2000);
    digits[0] = 1;
    for(int n = 2; n <= N; n++){
        
        fill(calcRes.begin(), calcRes.end(), 0);

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

        // for(int i = 0; i < digits.size(); i++){
        //     digits[i] = calcRes[i];
        // }
        digits = calcRes;

        // for(int i = 0; i < 10; i++){
        //     cout << digits[i] << ' ';
        // }
        // cout << '\n';
    }

    int cnt = 0;
    int idx = 0;
    while(digits[idx++] == 0) cnt++;

    cout << cnt << '\n';

    // vector<int> v1 = {1, 2, 3, 4};
    // v1.clear();

    // for(int i = 0; i < 4; i++){
    //     cout << v1[i] << ' ';
    // }
    // cout << '\n';

    // cout << v1.capacity() << '\n';
    // // Result
    // // 1 2 3 4 
    return 0;
}

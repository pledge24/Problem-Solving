#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;

    int K; cin >> K;
    long long sum = 0;
    stack<long long> s;
    for(int i = 0; i < K; i++){
        long long num; cin >> num;

        if(num == 0){
            sum -= s.top();
            s.pop();
        }
        else{
            sum += num;
            s.push(num);
        }
    }

    long long ans = sum;
    cout << ans << '\n';

    return 0;
}
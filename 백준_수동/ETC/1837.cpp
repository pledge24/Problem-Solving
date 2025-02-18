#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

bool isPrime(int n){

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) 
            return false;
    }
    
    return true;
}

int main(void){
    fastio;
    int P, K; cin >> P >> K;

    int primeNum = -1;
    for(int i = 2; i < K; i++){
        // 두 수의 곱으로 표현 안되는 경우
        if(P % i != 0) 
            continue;

        if(isPrime(i) && isPrime(P/i)){
            primeNum = min(i, P/i);
            break;
        }
    }

    if(primeNum == -1)
        cout << "GOOD" << '\n';
    else
        cout << "BAD" << " " << primeNum << '\n';

    return 0;
}
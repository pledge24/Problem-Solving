#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void printPrimeNumbers(int num){
    vector<int> arr(num+1);

    // 배열을 1부터 시작하는 값으로 채우기
    iota(arr.begin(), arr.end(), 1);

    for(int i = 2; i <= num; i++){
        if(arr[i] == 0) continue;

        cout << i << " ";
        for(int j = 1; i*j <= num; j++){
            arr[i*j] = 0;
        }
    }
    cout << '\n';
}

int main() {
	fastio;
    printPrimeNumbers(100);   
}
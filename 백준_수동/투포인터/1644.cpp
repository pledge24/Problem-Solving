#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

bool isPrime(int num){
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}
void fillPrimeList(vector<int>& primeList, int N){

    for(int i = 2; i <= N; i++){
        if(isPrime(i)) primeList.push_back(i);
    }
}

int main() {
	fastio;

    int N; cin >> N;

    vector<int> primeList;
    fillPrimeList(primeList, N);

    // for(int elem : primeList){
    //     cout << elem << ' ';
    // }
    // cout << '\n';

    int e = 0, sum = 0, ans = 0;
    for(int s = 0; s < primeList.size(); s++){
        while(e < primeList.size() && sum < N){
            sum += primeList[e];
            e++;
        }
        if(sum == N) ans++;

        sum -= primeList[s];
    }

    cout << ans << '\n';
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int LinearSieve(const int N)
{
    vector<int> minPrimeFactor(N+1, -1);
    vector<int> primes;

    int forCnt = 0;
    int setCnt = 0;
    int breakCnt = 0;

    bool isBreak = false;
    for(int i = 2; i <= N; i++)
    {
        isBreak = false;

        // 이전까지의 결과에서 합성수로 판정 X -> 소수임
        if(minPrimeFactor[i] == -1)
        {
            minPrimeFactor[i] = i;
            // ++setCnt;

            primes.push_back(i);
        }

        // 합성수 제거 시도
        for(int p : primes)
        {
            ++forCnt;

            // 곱할 소수 p가 최소 소인수가 될 수 없거나,
            // 곱한 수가 범위 초과시 break;
            if(p > minPrimeFactor[i] || p * i > N)
            {
                isBreak = true;
                break;
            }

            // 합성수의 최소 소인수 설정
            minPrimeFactor[p * i] = p;
            ++setCnt;
        }

        if(isBreak)
            breakCnt++;
    }

    cout << "forCnt: " << forCnt << '\n'; // 19334973
    cout << "setCnt: " << setCnt << '\n'; // 9335420
    cout << "breakCnt: " << breakCnt << '\n'; 

    // for(int p : primes)
    //     cout << p << ' ';
    // cout << '\n';

    // for(int p : minPrimeFactor)
    //     cout << p << ' ';
    // cout << '\n';

    return primes.size();
}

int main(){
    fastio;

    const int N = 10'000'000;
    int ans = LinearSieve(N);

    // int ans = 0;
    cout << "Num of Primes: " << ans << endl; // 664579

    return 0;
}

// Cnt관한 추가 설명
// if문 조건에 걸리지 않고 Primes 배열의 모든 소수를 순회하여
// for문이 끝나면 setCnt만큼 forCnt가 증가.
// if문에 걸려 끝나면 forCnt = setCnt + 1만큼 증가

// forCnt는 합성수 설정 횟수 + 1000만번
// 따라서, 2000만번 - (소수의 개수 + for문 끝까지 순회한 횟수)
// => forCnt
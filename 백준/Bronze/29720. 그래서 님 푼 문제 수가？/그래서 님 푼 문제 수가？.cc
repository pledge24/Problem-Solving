#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void)
{
    fastio;
    int N, M, K; cin >> N >> M >> K;
    int minLeft = min(M*(K-1) + 1, N);
    int maxLeft = min(M*K, N);

    cout << N - maxLeft << " " << N - minLeft << '\n';
    return 0;
}
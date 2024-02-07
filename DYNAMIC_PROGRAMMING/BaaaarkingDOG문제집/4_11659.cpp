#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0) // ㄷㄷ.... 이게 문제였다니;;

using namespace std;

int main(void){

    fastio;

    int N,M;
    cin >> N >> M;

    int num;
    vector<int> v1(N+1);    // i번째 까지 숫자의 합을 저장.

    for(int i=1; i<=N; i++){
        cin >> num;
        v1[i] = v1[i-1] + num;
    }

    int s, t;
    for(int i=0; i<M; i++){
        cin >> s >> t;
        cout << v1[t] - v1[s-1] << '\n';
    }

    return 0;
}
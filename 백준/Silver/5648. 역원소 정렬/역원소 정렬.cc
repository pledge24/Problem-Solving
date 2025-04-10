#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    vector<long long> v1(N);
    for(int i = 0; i < N; i++){
        string str; cin >> str;
        reverse(str.begin(), str.end());
        v1[i] = stoll(str);
    }

    sort(v1.begin(), v1.end());

    for(int i = 0; i < N; i++){
        cout << v1[i] << '\n';
    }

    return 0;
}
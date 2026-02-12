#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void startTest(){
    int N; cin >> N;

    if(N == 0){
        cout << 0 << '\n';
        return;
    }
    
    map<string, int> m;
    for(int i = 0; i < N; i++){
        string str1, str2;
        cin >> str1 >> str2;
        m[str2]++;
    }

    int ans = 1;
    for(auto it : m){
        ans *= it.second+1;
    }

    cout << ans - 1 << '\n';
}

int main(void){
    fastio;
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;
}
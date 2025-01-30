#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    int len; cin >> len;
    string s; cin >> s;
    
    string target = "I";
    for(int i = 0; i < N; i++){
        target += "OI";
    }

    map<string, int> m;
    for(int i = 0; i + target.length() - 1 < len; i++){
        m[s.substr(i, target.length())]++;
    }

    cout << m[target] << '\n';

    return 0;
}
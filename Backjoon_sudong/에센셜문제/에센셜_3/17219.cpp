#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int a, b; cin >> a >> b;

    map<string, string> m1;
    for(int i = 0; i < a; i++){
        string str1, str2;
        cin >> str1 >> str2;
        m1[str1] = str2;
    }

    for(int i = 0; i < b; i++){
        string str1; cin >> str1;
        cout << m1[str1] << '\n';
    }
    return 0;
}
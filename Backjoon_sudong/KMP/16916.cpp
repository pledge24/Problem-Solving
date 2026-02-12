#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;

    string S, P; cin >> S >> P;

    char* str1 = new char [S.length()+1];
    char* str2 = new char [P.length()+1];

    strcpy(str1, S.c_str());
    strcpy(str2, P.c_str());
    int ans = strstr(str1, str2) != NULL;

    cout << ans << '\n';
}
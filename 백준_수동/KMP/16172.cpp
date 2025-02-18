#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    string s1, s2; cin >> s1 >> s2;

    string temp_s1 = s1;
    s1.clear();
    for(char c : temp_s1){
        if(!isdigit(c)) s1 += c;
    }

    char* str1 = new char [s1.length()+1];
    char* str2 = new char [s2.length()+1];

    strcpy(str1, s1.c_str());
    strcpy(str2, s2.c_str());

    int ans = strstr(str1, str2) != NULL;

    cout << ans << '\n';
    return 0;
}
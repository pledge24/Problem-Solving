#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        string str1, str2; cin >> str1 >> str2;

        map<char, int> m1, m2;
        for(char c: str1){
            m1[c]++;
        }

        for(char c: str2){
            m2[c]++;
        }

        bool flag = true;
        if(str1.length() != str2.length())
            flag = false;
            
        for(int c = 'a'; c <= 'z'; c++){
            if(m1[c] < m2[c])
                flag = false;
        }

        string ans = flag ? "Possible" : "Impossible";

        cout << ans << '\n';
    }

    return 0;
}
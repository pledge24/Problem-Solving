#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;

    string str1, str2; cin >> str1 >> str2;
    stack<pair<char, int>> s1;  // character cursorPos(streaks)
    for(const char c : str1){
        int cursor = s1.empty() ? 0 : s1.top().second;

        if(c == str2[cursor]){  // isMatched
            s1.push({c, cursor+1});
            if(cursor+1 == str2.length()){

                int str2Len = str2.length();
                while(str2Len > 0){
                    s1.pop();
                    str2Len--;
                }
            }
        }
        else{                   // Not Matched
            cursor = c == str2[0] ? 1 : 0;
            s1.push({c, cursor});
        }
    }

    string ans = "";
    while(!s1.empty()){
        ans += s1.top().first;
        s1.pop();
    }

    if(ans.length() > 0)
        reverse(ans.begin(), ans.end());
    else
        ans = "FRULA";

    cout << ans << '\n';
       
    return 0;
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    string str; cin >> str;
    map<char, int> m;

    for(char c : str){
        m[c]++;
    }

    // 홀수가 2개 이상 있으면 망한다.
    int oddCnt = 0;
    for(char c = 'A'; c <= 'Z'; c++){
        if(m[c] == 0) continue;
        if(m[c] % 2 == 1) oddCnt++;
    }
    
    string ans = "";
    if(oddCnt > 1){
        ans = "I'm Sorry Hansoo";
    }
    else{
        char oddAlpha = ' ';
        for(char c = 'A'; c <= 'Z'; c++){
            int cnt = m[c];
            if(cnt % 2 == 1){
                oddAlpha = c;
            }
            ans.append(cnt/2, c);
        }
        string rStr = ans;
        reverse(rStr.begin(), rStr.end());
        
        if(oddAlpha != ' '){
            ans += oddAlpha;
        }

        ans += rStr;
    }

    cout << ans << '\n';
}
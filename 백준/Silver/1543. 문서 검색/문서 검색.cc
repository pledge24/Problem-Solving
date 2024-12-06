#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    string str; getline(cin, str);
    string target; getline(cin, target);

    int ans = 0;
    int idx = 0;
    while(true){
        idx = str.find(target, idx);
        if(idx == string::npos) break;
        
        ans++;
        idx += target.length();
    }

    cout << ans << '\n';
    
}
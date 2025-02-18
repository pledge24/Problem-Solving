#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

bool isAkaraka(string &str, int start, int len){
    if(len == 1) return true;
    int preStartIdx = start;
    int postStartIdx = (start + len + 1) / 2;

    string prefix = str.substr(start, len/2);
    string rPostfix = str.substr(postStartIdx, len/2);
    reverse(rPostfix.begin(), rPostfix.end());

    if(prefix != rPostfix) return false;

    return isAkaraka(str, preStartIdx, len/2) && isAkaraka(str, postStartIdx, len/2);
}

int main() {
	fastio;
    string str; cin >> str;
    int len = str.length();

    string ans = isAkaraka(str, 0, len) ? "AKARAKA" : "IPSELENTI";

    cout << ans << '\n';
    
}
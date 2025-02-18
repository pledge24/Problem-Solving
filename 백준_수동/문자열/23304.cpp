#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    string str; cin >> str;
    int len = str.length();

    bool isAkaraka = false;
    if(len == 1){
        isAkaraka = true;
    }
    else{
        // 짝수랑 홀수 상관없이 사용할 수 있나?
        string left = str.substr(0, len/2);
        string right = str.substr((len+1)/2, len/2);

        isAkaraka = left == right ? true : false;
    }

    string ans = isAkaraka ? "AKARAKA" : "IPSELENTI";

    cout << ans << '\n';
    
}
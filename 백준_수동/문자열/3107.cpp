#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// 빈칸 스플릿은 하고 싶을 때도 있다.
// 어떻게 하면 좋을까?
vector<string> split(string &str, string delimiter){
    vector<string> ret;

    int idx = 0;
    while(idx < str.length()){
        int nextIdx = str.find(delimiter, idx);
        if(nextIdx == string::npos){
            nextIdx = str.length();
        }
        if(idx < str.length()){
            ret.push_back(str.substr(idx, nextIdx - idx));
        }

        idx = nextIdx + delimiter.length();
    }

    return ret;
}

int main() {
	fastio;

    string str; cin >> str;

    string delimiter = ":";
    vector<string> splitted = split(str, delimiter);

    enum {ALL_ZERO = 0, FULL = 4};
    string ans = "";
    bool todo = false;
    for(string s : splitted){
        if(s.length() == FULL)
            ans += (s + delimiter);
        else if(s.length() == ALL_ZERO && !todo){
            int addCount = 8 - splitted.size() + 1;
            for(int x = 0; x < addCount; x++){
                ans.append("0000:");
            }
            todo = true;
        }
        else{
            int addCount = 4 - s.length();
            ans.append(addCount, '0');
            ans += (s + delimiter);
        }
    }

    ans.erase(ans.length()-1);

    cout << ans << '\n';

    
}
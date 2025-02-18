#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// delimiter의 종류가 1개일 때(길이가 2이상인 것도 가능) 
vector<string> split(string& str, string& delimiter){
    vector<string> ret;
    int idx = 0;
    while(idx < str.size()){
        int nextIdx = str.find(delimiter, idx);
        if(nextIdx == string::npos) nextIdx = str.size();
        if(nextIdx - idx > 0)
            ret.push_back(str.substr(idx, nextIdx-idx));
        idx = nextIdx + delimiter.size();
    }

    return ret;
}
int main() {
	fastio;

    
}
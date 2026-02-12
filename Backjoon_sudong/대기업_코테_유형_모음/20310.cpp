#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    string str; cin >> str;

    int zeroN = 0;
    int oneN = 0;
    for(char c : str){
        if(c == '0') zeroN++;
        else oneN++;
    }

    zeroN /= 2;
    oneN /= 2;
    vector<bool> removed(str.length());
    for(int i = str.length()-1; i >= 0; i--){
        if(str[i] == '0' && zeroN > 0){
            removed[i] = true;
            zeroN--;
        }
    }

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '1' && oneN > 0){
            removed[i] = true;
            oneN--;
        }
    }

    string ans = "";
    for(int i = 0; i < removed.size(); i++){
        if(!removed[i])
            ans += str[i];
    }

    cout << ans << '\n';

    return 0;
}
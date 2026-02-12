#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    
    vector<int> v1(10);
    string str; cin >> str;
    for(char c : str){
        if(c == '9')
            c = '6';
        v1[c-'0']++;
    }

    int N = (v1[6] + v1[9] + 1) / 2;
    v1[6] = v1[9] = N;
    
    cout << *max_element(v1.begin(), v1.end()) << '\n';

    return 0;
}
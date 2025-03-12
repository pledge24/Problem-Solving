#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define HASH(str) hash<string>{}(str)

using namespace std;

int main(void){
    fastio; 

    string str; cin >> str;
    set<size_t> s;
    for(int i = 0; i < str.length(); i++){
        for(int size = 1; i + size <= str.length(); size++){
            s.insert(HASH(str.substr(i, size)));
        }
    }

    cout << s.size() << '\n';

    return 0;
}
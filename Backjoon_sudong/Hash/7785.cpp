#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    set<string> s;
    for(int i = 0; i < N; i++){
        string name, state;
        cin >> name >> state;

        if(state == "enter"){
            s.insert(name);
        }
        else{
            s.erase(name);
        }
    }

    for(auto it = s.rbegin(); it != s.rend(); it++)
        cout << *it << '\n';

    return 0;
}
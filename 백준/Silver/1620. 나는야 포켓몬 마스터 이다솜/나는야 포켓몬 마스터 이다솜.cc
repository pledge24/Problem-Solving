#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int M, N; cin >> M >> N;

    vector<string> v1(M+1);
    map<string, int> m;
    for(int i = 1; i <= M; i++){
        string name;
        cin >> name;
        v1[i] = name; m[name] = i;
    }

    for(int i = 0; i < N; i++){
        string s; cin >> s;

        if(m[s] > 0){
            cout << m[s] << '\n';
        }
        else{
            int idx = stoi(s);
            cout << v1[idx] << '\n';
        }
    }

    return 0;
}

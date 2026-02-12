#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int K, L; cin >> K >> L;

    int order = 0;
    map<string, int> m1;
    for(int i = 0; i < L; i++){
        string studentId; cin >> studentId;
        m1[studentId] = order++;
    }

    vector<pair<int, string>> v1;
    for(pair<string, int> p : m1){
        v1.push_back(make_pair(p.second, p.first));
    }

    sort(v1.begin(), v1.end());

    for(int i = 0; i < min(K, (int)v1.size()); i++){
        cout << v1[i].second << '\n'; 
    }

    return 0;
}


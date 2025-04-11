#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

map<int, int> m2;

struct cmp{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
        if(p1.second != p2.second)
            return p1.second > p2.second;
        
        return m2[p1.first] < m2[p2.first];
    }
};

int main(void){
    fastio;
    int N, C; cin >> N >> C;
    map<int, int> m1;   
    for(int i = 0; i < N; i++){
        int num; cin >> num;
        m1[num]++;
        if(m2.find(num) == m2.end())
            m2[num] = i;
    }

    vector<pair<int, int>> v1(m1.begin(), m1.end());
    sort(v1.begin(), v1.end(), cmp());
    
    for(auto elem : v1){
        int cnt = elem.second;
        while(cnt--)
            cout << elem.first << ' ';
    }
    cout << '\n';

    return 0;
}
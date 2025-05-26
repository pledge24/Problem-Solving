#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using strData = pair<string, int>;

struct cmp{
    bool operator()(const strData& s1, const strData& s2){
        // 1) 개수가 많음
        if(s1.second != s2.second)
            return s1.second < s2.second;

        // 2) 더 길다
        if(s1.first.length() != s2.first.length())
            return s1.first.length() < s2.first.length();

        // 3) 사전순
        return s1.first > s2.first;
    }
};

int main(void){
    fastio;
    int N, M;
    cin >> N >> M;

    map<string, int> m1;
    for(int i = 0; i < N; i++){
        string str; cin >> str;
        if(str.length() < M)
            continue;

        m1[str]++;
    }

    priority_queue<strData, vector<strData>, cmp> pq;
    for(auto elem : m1){
        pq.push(elem);
    }

    while(!pq.empty()){
        cout << pq.top().first << '\n';
        pq.pop();
    }

    return 0;
}
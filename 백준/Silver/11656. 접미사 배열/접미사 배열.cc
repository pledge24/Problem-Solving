#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct cmp{
    bool operator()(const string& s1, const string& s2){
        return s1 < s2;
    }
};

int main(void){
    fastio;
    string str; cin >> str;

    priority_queue<string, vector<string>, greater<string>> pq;
    for(int i = 0; i < str.length(); i++){
        pq.push(str.substr(i, str.length()-i));
    }

    while(!pq.empty()){
        cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}
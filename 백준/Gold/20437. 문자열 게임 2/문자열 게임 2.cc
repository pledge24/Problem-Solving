#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define INF INT32_MAX
using namespace std;

void startTest(){
    string str; cin >> str;
    int K; cin >> K;

    map<char, vector<int>> m1;
    for(int i = 0; i < str.length(); i++){
        char c = str[i];
        m1[c].push_back(i);
    }

    // 1) 어떤 문자를 정확히 K개 포함하는 가장 짧은 연속 문자열
    int minLen = INF;
    for(auto elem : m1){
        char c = elem.first;
        vector<int>& v1 = elem.second;
        if(v1.size() < K)
            continue;

        for(int i = 0; (i + K - 1) < v1.size(); i++){
            int len = v1[i+K-1] - v1[i] + 1;
            minLen = min(minLen, len);
            // cout << "c : " << c << " " << v1[i+K-1] << " " << v1[i] << '\n';
        }
    }

    // 2) 어떤 문자를 정확히 K개를 포함하고, 문자열의 첫 번째와 마지막 글자가 해당 문자로 같은 가장 긴 연속 문자열
    int maxLen = 0;
    for(auto elem : m1){
        char c = elem.first;
        vector<int>& v1 = elem.second;
        if(v1.size() < K)
            continue;

        for(int i = 0; (i + K - 1) < v1.size(); i++){
            int len = v1[i+K-1] - v1[i] + 1;
            maxLen = max(maxLen, len);
            // cout << "c : " << c << " " << v1[i+K-1] << " " << v1[i] << '\n';
        }
    }

    if(minLen != INF && maxLen != 0){
        cout << minLen << " " << maxLen << '\n';
    }
    else{
        cout << -1 << '\n';
    }
}

int main(void){
    fastio;

    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;
}
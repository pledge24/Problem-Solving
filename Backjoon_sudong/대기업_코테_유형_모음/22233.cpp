#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define OUT

using namespace std;

void split(string& str, string delimiter, vector<string>& res){
    int idx = 0;
    while(idx < str.size()){
        int nextIdx = str.find(delimiter, idx);
        if(nextIdx == string::npos) nextIdx = str.size();
        if(nextIdx - idx > 0)
            res.push_back(str.substr(idx, nextIdx-idx));
        idx = nextIdx + delimiter.size();
    }

}

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    unordered_set<string> s1;
    for(int i = 0; i < N; i++){
        string str; cin >> str;
        s1.insert(str);
    }

    cin.ignore();
    for(int i = 0; i < M; i++){
        string line; 
        getline(cin, line);

        vector<string> res;
        split(line, ",", OUT res);
        
        for(const string& elem : res){
            s1.erase(elem);
        }

        cout << s1.size() << '\n';
    }

    return 0;
}
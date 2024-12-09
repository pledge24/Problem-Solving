#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// delimiter의 종류가 1개일 때(길이가 2이상인 것도 가능)
vector<string> split(string &str, string &delimiter)
{
    vector<string> ret;
    int idx = 0;
    while (idx < str.size())
    {
        int nextIdx = str.find(delimiter, idx);
        if (nextIdx == string::npos)
            nextIdx = str.size();
        if (nextIdx - idx > 0)
            ret.push_back(str.substr(idx, nextIdx - idx));
        idx = nextIdx + delimiter.size();
    }

    return ret;
}

bool isNum(char c){
    return '0' <= c && c <= '9';
}

void extractNumber(auto& pq, string str){

    for(int i = 0; i < str.length(); i++){
        if(!isNum(str[i])) str[i] = '_';
    }

    string delimiter = "_";
    vector<string> splitted = split(str, delimiter);

    for(string& s : splitted){
        // trim zero;
        int pos = 0;
        while(s[pos] == '0' && pos < s.length()){
            pos++;
        }

        s = s.substr(pos, s.length()-pos);

        if(s.length() == 0) s = "0";
        pq.push(s);
    }
}

int main() {
	fastio;
    int N; cin >> N;
    
    auto cmp = [](string s1, string s2){
        if(s1.length() == s2.length()){
            return s1 > s2;
        }
        
        return s1.length() > s2.length();
    };

    priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        extractNumber(pq, str);
    }

    while(!pq.empty()){
        string s = pq.top(); pq.pop();
        cout << s << '\n';
    }
}
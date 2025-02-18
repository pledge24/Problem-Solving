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

string getResult(string mixed, vector<string>& v1){

    string delimiter = " ";
    string empty = "";
    map<string, bool> noises;
    for(string s : v1){
        vector<string> splitted = split(s, delimiter);
        noises[splitted.back()] = true;
    }

    string ret = "";
    vector<string> splitted = split(mixed, delimiter);
    for(string s : splitted){
        if(noises[s] > 0)
            continue;
        ret += s + " ";
    }

    return ret;
}

int main() {
	fastio;

    string input; getline(cin, input);
    int T = stoi(input);
    for(int i = 0; i < T; i++){
        string mixed; getline(cin, mixed);

        vector<string> v1; 
        string s; getline(cin, s);
        string eof = "what does the fox say?";
        while(s != eof){
            v1.push_back(s);
            getline(cin, s);
        }
        
        string ans = getResult(mixed, v1);
        cout << ans << '\n';
    }
    
}
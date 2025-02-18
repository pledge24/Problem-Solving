#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

string peekString(const string &str, vector<bool>& visited, int j){
    string ret = "";
    for(int i = 0; i < visited.size(); i++){
        if(visited[i] || i == j){
            ret += str[i];
        }
    }

    return ret;
}

int main() {
	fastio;

    string str; cin >> str;

    vector<bool> visited(str.length());
    for(int i = 0; i < str.length(); i++){

        string nextStr = "";
        bool isFirst = true;
        int idx = -1;
        for(int j = 0; j < str.length(); j++){
            if(visited[j]) continue;

            string curStr = peekString(str, visited, j);

            // i번째 반복에 i-1의 길이를 가졌다면 그냥 추가하고,
            if(isFirst){
                // todo
                nextStr = curStr;
                idx = j;

                isFirst = false;
                continue;
            }
            else if(curStr < nextStr){
                nextStr = curStr;
                idx = j;
            }
            
        }

        visited[idx] = true;
        cout << nextStr << '\n';
    }

}
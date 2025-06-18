#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define OUT
#define ALPHA 30
using namespace std;

void split(const string& str, int& pos, vector<bool>& visited){
    char delimeter = ' ';

    int idx = 0;
    while(idx < str.size()){
        int nextIdx = str.find(delimeter, idx);
        if(nextIdx == string::npos)
            nextIdx = str.size();

        if(nextIdx - idx > 0){
            int c = tolower(str[idx]) - 'a';
            if(visited[c] == false){
                pos = idx;
                return;
            }
        }
        
        idx = nextIdx + 1;
    }
}

int main(void){
    fastio;
    int N; cin >> N;

    vector<bool> visited(ALPHA); 
    cin.ignore();
    for(int i = 0; i < N; i++){
        string str; getline(cin, str);

        int pos = -1;
        split(str, OUT pos, OUT visited);

        bool found = false;
        if(pos != -1){
            found = true;
            int c = tolower(str[pos]) - 'a';
            visited[c] = true;

            str.insert(pos+1, "]");
            str.insert(pos, "[");
        }

        if(!found){
            for(int x = 0; x < str.length(); x++){
                if(!isalpha(str[x]))
                    continue;

                int c = tolower(str[x]) - 'a';

                if(!visited[c]){
                    visited[c] = true;
                    str.insert(x+1, "]");
                    str.insert(x, "[");
                    break;
                }
            }
        }

        cout << str << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void ApplyCmd(list<char>& l1, list<char>::iterator& cursor, char cmd){
    switch (cmd)
    {
    case 'L':
        if(cursor != l1.begin())
            cursor--;
        break;
    case 'D':
        if(cursor != l1.end())
            cursor++;
        break;    
    case 'B':
        if(cursor != l1.begin()){
            cursor--;
            cursor = l1.erase(cursor);
        }
        break;
    case 'P':
        char c; cin >> c;
        cursor = l1.insert(cursor, c);
        if(cursor != l1.end())
            cursor++;
        break;
    default:
        break;
    }
}

int main(void){
    fastio;
    list<char> l1;
    string str; cin >> str;
    for(char c : str){
        l1.push_back(c);
    }

    auto cursor = l1.end();
    int M; cin >> M;
    for(int i = 0; i < M; i++){
        char cmd; cin >> cmd;
        
        if(cmd == 'P'){
            ApplyCmd(l1, cursor, cmd);
        }
        else{
            ApplyCmd(l1, cursor, cmd);
        }

        // for(const char& c : l1)
        //     cout << c;
        // cout << '\n';
    }

    for(const char& c : l1)
        cout << c;
    cout << '\n';

    return 0;
}
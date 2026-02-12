#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using Time = pair<int, int>;

Time splitTime(const string& str){
    int hh = stoi(str.substr(0, 2));
    int mm = stoi(str.substr(3, 2));
    return make_pair(hh, mm);
}

int main(void){
    fastio;
    string S, E, Q; cin >> S >> E >> Q;

    Time timeS = splitTime(S);
    Time timeE = splitTime(E);
    Time timeQ = splitTime(Q);

    map<string, int> m;
    while(!cin.eof()){
        string time, nickname; 
        cin >> time >> nickname;

        if(time.length() != 5)
            break;

        Time timeCur = splitTime(time);

        if(timeCur <= timeS)
            m[nickname] |= 1; // entry Flag
        else if(timeE <= timeCur && timeCur <= timeQ)
            m[nickname] |= 2; // exit Flag

    }

    int cnt = 0;
    for(auto it : m){
        // cout << it.first << " " << it.second << '\n';
        if(it.second == 3)
            cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
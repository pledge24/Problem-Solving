#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void dfsUtil(deque<char>& dqS, deque<char>& dqT, bool reversed, bool& res){
    // for(auto elem : dqT)
    //     cout << elem << ' ';
    // cout << '\n';
    
    if(dqS.size() == dqT.size()){
        deque<char> tempDqT(dqT);
        if(reversed)
            reverse(tempDqT.begin(), tempDqT.end());

        res |= (dqS == tempDqT);
        return;
    }

    char bChar, fChar;
    bChar = !reversed ? dqT.back() : dqT.front();
    fChar = !reversed ? dqT.front() : dqT.back();

    if(bChar == 'A'){
        // remove Back elem
        if(!reversed) dqT.pop_back();
        else dqT.pop_front();

        dfsUtil(dqS, dqT, reversed, res);

        // reAdd Back elem
        if(!reversed) dqT.push_back(bChar);
        else dqT.push_front(bChar);
    }

    if(fChar == 'B'){
        // remove Front elem
        if(!reversed) dqT.pop_front();
        else dqT.pop_back();

        dfsUtil(dqS, dqT, !reversed, res);

        // reAdd Front elem
        if(!reversed) dqT.push_front(fChar);
        else dqT.push_back(fChar);
    }
    
    return;
}

bool dfs(deque<char>& dqS, deque<char>& dqT){
    bool res = false;
    bool reversed = false;

    dfsUtil(dqS, dqT, reversed, res);

    return res;
}

int main(void){
    fastio;
    string S, T; cin >> S >> T;

    deque<char> dqS, dqT;
    for(char c : S)
        dqS.push_back(c);
    for(char c : T)
        dqT.push_back(c);

    int ans = dfs(dqS, dqT);

    cout << ans << '\n';

    return 0;
}
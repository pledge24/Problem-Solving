#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    pair<int, int> range = make_pair(-1, -1);
    int s = -1;
    int maxLen = 0;
    int len = 0;
    for(int i = 1; i < name.length(); i++)
    {
        if(name[i] == 'A')
        {
            len++;
            if(len == 1)
                s = i;
        }
        else
        {
            if(len > maxLen)
            {
                maxLen = len;
                range = make_pair(s, i-1);
            }
            len = 0;
        }
    }
    
    if(len > maxLen)
    {
        maxLen = len;
        range = make_pair(s, name.length()-1);
    }
    
    // cout << range.first << " " << range.second << '\n';
    // cout << maxLen << '\n';
    
    int vMoveN = 0;
    for(int i = 0; i < name.length(); i++)
    {
        if(name[i] != 'A')
            vMoveN = i;
    }
    
    if(range != make_pair(-1, -1))
    {
        int rMoveN = range.first - 1;
        int lMoveN = name.length() - range.second - 1;
        int uTurnN = min(rMoveN, lMoveN)*2 + max(rMoveN, lMoveN);
        
        // cout << rMoveN << " " << lMoveN << '\n';
        
        vMoveN = min(vMoveN, uTurnN);
    }
    
    
    int hMoveN = 0;
    for(char c : name)
    {
        int upN = c - 'A';
        int downN = ('A' + 26) - c;
        
        // cout << upN << " " << downN << '\n';
        hMoveN += min(upN, downN);
    }
    
    answer = vMoveN + hMoveN;
    
    return answer;
}
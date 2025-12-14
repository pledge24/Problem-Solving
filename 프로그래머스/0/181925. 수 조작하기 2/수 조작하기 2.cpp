#include <bits/stdc++.h>

using namespace std;

map<int, char> gapToCmd = 
{
    make_pair(1, 'w'),
    make_pair(-1, 's'),
    make_pair(10, 'd'),
    make_pair(-10, 'a')
};

string solution(vector<int> numLog) {
    string answer = "";
    
    bool first = true;
    int prevNum = 0;
    for(const int& curNum : numLog)
    {
        if(first)
        {
            first = false;
            prevNum = curNum;
            continue;
        }
        
        int gap = curNum - prevNum;
        answer += gapToCmd[gap];
        prevNum = curNum;
    }
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(s / n < 1)
        answer = {-1};
    else
    {
        int baseNum = s / n;
        int carryN = s % n;
        
        cout << baseNum << ' ' << carryN << '\n';
        for(int i = 0; i < n; i++)
        {
            answer.push_back(baseNum + (i >= n - carryN));
        }
    }
    
    return answer;
}

    
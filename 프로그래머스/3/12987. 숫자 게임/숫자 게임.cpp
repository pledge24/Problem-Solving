#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = -1;
    
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    
    int cursorB = 0;
    int wins = 0;
    for(int cursorA = 0; cursorA < A.size(); cursorA++)
    {
        while(A[cursorA] >= B[cursorB] && cursorB < B.size())
        {
            cursorB++;
        }
        
        if(cursorB < B.size())
        {
            // cout << A[cursorA] << "<-A B->" << B[cursorB] << '\n';
            wins++;
            cursorB++;
        }
    }
    
    answer = wins;
    
    return answer;
}
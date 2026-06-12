#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int div = 2;
    set<int> s1;
    while(div <= n)
    {
        if(n % div == 0)
        {
            s1.insert(div);
            n /= div;
        }
        else
            div++;
            
    }
    
    answer.assign(s1.begin(), s1.end());
    
    return answer;
}
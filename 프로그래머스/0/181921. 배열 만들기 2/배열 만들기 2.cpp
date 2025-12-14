#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    // Naive
    for(int num = l; num <= r; num++)
    {
        const string& str = to_string(num);
        bool valid = true;
        for(const char& c : str)
        {
            if(c != '0' && c != '5')
            {
                valid = false;
                break;
            }
        }
        
        if(valid)
        {
            answer.push_back(num);
        }
    }
    
    if(answer.empty())
        answer.push_back(-1);
    
    return answer;
}
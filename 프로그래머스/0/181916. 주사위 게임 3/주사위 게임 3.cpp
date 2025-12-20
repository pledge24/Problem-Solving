#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    
    map<int, int> m;    // <value, count>
    m[a]++;
    m[b]++;
    m[c]++;
    m[d]++;
    
    auto maxit = max_element(m.begin(), m.end(), [](const auto& p1, const auto& p2){ return p1.second < p2.second; }); 
    int maxN = maxit->second;
    switch(maxN)
    {
        case 4:
            {
                int p = m.begin()->first;
                answer = 1111 * p;
                break;
            }
        case 3:
            {
                int p = -1;
                int q = -1;
                for(const auto& pair_ : m)
                {
                    if(pair_.second == 3)
                        p = pair_.first;
                    else
                        q = pair_.first;
                }
                
                answer = pow(10 * p + q, 2);
                break;
            }
        case 2:
            {
                if(m.size() == 2)
                {
                    int lhs = -1;
                    int rhs = -1;
                    for(const auto& p1: m)
                    {
                        int value = p1.first;
                        
                        lhs = lhs == -1 ? value : lhs + value;
                        rhs = rhs == -1 ? value : abs(rhs - value);
                    }
                    
                    answer = lhs * rhs;
                }
                else
                {
                    answer = 1;
                    for(const auto& p1 : m)
                    {
                        answer *= p1.second == 1 ? p1.first : 1;
                    }
                    
                }
                
                break;
            }
        case 1:
            {
                bool first = true;
                for(const auto& p1 : m)
                    {
                        if(first)
                        {
                            answer = p1.first;
                            first = false;
                            continue;
                        }
                    
                        answer = min(answer, p1.first);
                    }
                
                break;
            }
        default:
            break;
    }
    
    return answer;
}
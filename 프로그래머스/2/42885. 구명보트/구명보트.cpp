#include <bits/stdc++.h>

using namespace std;

// 구명보트는 2명을 태운다. 무게제한도 있다.
// 구출할 수 없는 경우는 없다(항상 몸무게 <= 무게제한)

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    std::sort(people.begin(), people.end());
    int start = 0;
    int end = people.size()-1;
    
    while(start <= end)
    {
        if(start == end)
        {
            answer++;
            break;
        }
        
        int minW = people[start];
        int maxW = people[end];
        
        if(minW + maxW <= limit)
        {
            start++;
            end--;
        }
        else
        {
            end--;
        }
        
        answer++;
    }
    
    return answer;
}
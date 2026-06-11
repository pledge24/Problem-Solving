#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    std::sort(numbers.begin(), numbers.end());
    
    answer = numbers[0] * numbers[1];
    for(int i = 1; i < numbers.size() - 1; i++)
    {
        int num = numbers[i] * numbers[i+1];
        answer = max(answer, num);
    }
    
    return answer;
}
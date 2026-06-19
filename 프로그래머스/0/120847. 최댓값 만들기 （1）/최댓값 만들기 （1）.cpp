#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    std::sort(numbers.begin(), numbers.end());
    
    int N = numbers.size();
    answer = numbers[N-1] * numbers[N-2];
    
    return answer;
}
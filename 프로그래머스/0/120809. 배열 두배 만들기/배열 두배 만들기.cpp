#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    std::transform(numbers.begin(), numbers.end(), 
                   std::back_inserter(answer), 
                   [](int n) { return n * 2; });
    return answer;
}
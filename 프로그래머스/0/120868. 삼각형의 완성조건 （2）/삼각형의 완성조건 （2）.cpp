#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    int maxN = std::max(sides[0], sides[1]);
    int minLen = maxN - std::min(sides[0], sides[1]) + 1;
    int maxLen = (sides[0] + sides[1]) - 1;
    
    answer =  maxLen - minLen + 1;
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    int c = max_element(sides.begin(), sides.end()) - sides.begin();
    int sum = 0;
    for(int i = 0; i < sides.size(); i++)
    {
        sum += i != c ? sides[i] : 0;
    }
    
    answer = sum > sides[c] ? 1 : 2;
    
    return answer;
}
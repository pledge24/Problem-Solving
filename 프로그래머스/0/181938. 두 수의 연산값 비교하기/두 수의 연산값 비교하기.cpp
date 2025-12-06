#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    int res1 = stoi(to_string(a) + to_string(b));
    int res2 = 2 * a * b;
    
    answer = max(res1, res2);
    
    return answer;
}
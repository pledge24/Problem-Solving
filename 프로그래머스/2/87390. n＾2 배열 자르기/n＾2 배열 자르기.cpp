#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    answer.resize(right-left+1);
    
    for(long long i = left; i <= right; i++){
        answer[i - left] = max(i/n, i%n) + 1;
    }
    
    return answer;
}
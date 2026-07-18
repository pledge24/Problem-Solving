#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    std::sort(array.begin(), array.end());
    
    answer = array[array.size() / 2];
    
    return answer;
}
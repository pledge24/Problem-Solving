#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int len = 1;
    while(len < arr.size())
        len <<= 1;
    
    answer.resize(len);
    std::copy(arr.begin(), arr.end(), answer.begin());
    
    return answer;
}
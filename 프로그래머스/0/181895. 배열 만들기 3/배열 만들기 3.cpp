#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    
    vector<int>& first_interval = intervals[0];
    vector<int>& second_interval = intervals[1];
    
    std::copy(arr.begin() + first_interval[0], arr.begin() + first_interval[1] + 1, std::back_inserter(answer));
    std::copy(arr.begin() + second_interval[0], arr.begin() + second_interval[1] + 1, std::back_inserter(answer));
    
    return answer;
}
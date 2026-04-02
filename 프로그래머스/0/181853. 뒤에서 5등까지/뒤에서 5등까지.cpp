#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    std::sort(num_list.begin(), num_list.end());
    
    answer.assign(num_list.begin(), num_list.begin()+5);
    return answer;
}
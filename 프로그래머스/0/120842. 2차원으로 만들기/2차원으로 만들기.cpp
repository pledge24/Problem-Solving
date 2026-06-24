#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    for(int i = 0; i < num_list.size(); i += n)
    {
        vector<int> v;
        std::copy(num_list.begin() + i, num_list.begin() + i + n, std::back_inserter(v)); 
        answer.push_back(v);
    }
    
    return answer;
}
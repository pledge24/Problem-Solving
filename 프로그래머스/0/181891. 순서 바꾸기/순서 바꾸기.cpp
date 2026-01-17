#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    
    for(int i = 0; i < num_list.size(); i++)
    {
        int realIdx = (i + n) % num_list.size();
        int num = num_list[realIdx];
        
        answer.push_back(num);
    }
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    auto start = arr.begin();
    auto end = arr.end();
    
    for(int i = 0; i < query.size(); i++)
    {      
        if(i % 2 == 0)
            end = start + query[i] + 1;
        else
            start = start + query[i];
        
        // cout << start << " " << end << '\n';
    }
    
    std::copy(start, end, back_inserter(answer));
    
    return answer;
}
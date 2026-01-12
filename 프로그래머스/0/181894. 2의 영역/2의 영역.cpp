#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    auto it = find(arr.begin(), arr.end(), 2);
    if(it == arr.end())
    {
        return {-1};
    }
    
    int start = it - arr.begin();
    int end = start;
    for(int i = start+1; i < arr.size(); i++)
    {
        if(arr[i] == 2)
        {
            end = i;
        }
    }
    std::copy(arr.begin()+start, arr.begin()+end+1, back_inserter(answer));
    
    return answer;
}
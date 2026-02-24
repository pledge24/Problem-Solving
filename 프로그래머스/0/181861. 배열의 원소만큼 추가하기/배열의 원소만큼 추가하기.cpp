#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(int elem : arr)
    {
        for(int i = 0; i < elem; i++)
        {
            answer.push_back(elem);
        }
    }
    
    return answer;
}
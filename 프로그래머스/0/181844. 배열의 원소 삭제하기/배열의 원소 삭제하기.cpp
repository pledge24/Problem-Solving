#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    
    for(int elem : arr)
    {
        bool b = false;
        for(int d : delete_list)
        {
            if(elem == d)
            {
                b = true;
                break;
            }
        }
        
        if(!b)
            answer.push_back(elem);
    }
    
    return answer;
}
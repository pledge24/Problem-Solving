#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    for(int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        bool f = flag[i];
        
        if(f)
        {
            for(int cnt = 0; cnt < num*2; cnt++)
            {
                answer.push_back(num);    
            }
            
        }
        else
        {
            for(int cnt = 0; cnt < num; cnt++)
            {
                answer.pop_back();   
            }
        }
    }
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int prevNum = -1;
    for(int elem : arr){
        if(elem != prevNum){
            answer.push_back(elem);
        }
        
        prevNum = elem;
    }
    
    return answer;
}
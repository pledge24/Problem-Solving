#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer;
    
    int len = arr.size();
    int target = !(len % 2);
    for(int i = 0; i < len; i++)
    {
        int num = arr[i];
        if(i % 2 == target)
            num += n;
        
        answer.push_back(num);
    }
    
    return answer;
}
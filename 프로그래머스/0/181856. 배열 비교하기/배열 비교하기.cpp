#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
    
    
    if(arr1.size() < arr2.size())
        return -1;
    else if(arr1.size() > arr2.size())
        return 1;
    else
    {
        int accu1 = std::accumulate(arr1.begin(), arr1.end(), 0);
        int accu2 = std::accumulate(arr2.begin(), arr2.end(), 0);
        
        if(accu1 < accu2)
            return -1;
        else if(accu1 > accu2)
            return 1;
    }
    return answer;
}
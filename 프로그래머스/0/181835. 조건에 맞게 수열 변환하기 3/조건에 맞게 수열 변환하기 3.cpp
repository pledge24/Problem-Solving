#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    for(int elem : arr)
    {
        answer.push_back(k % 2 > 0 ? elem*k : elem+k);
    }
    
    return answer;
}
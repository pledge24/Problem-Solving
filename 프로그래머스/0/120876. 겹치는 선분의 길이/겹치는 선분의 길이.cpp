#include <bits/stdc++.h>

using namespace std;

const int MAXRNG = 201; // -100 ~ 100

int solution(vector<vector<int>> lines) {
    int answer = 0;
    vector<int> diff(MAXRNG);
    int bias = 100;
    
    for(const vector<int>& l : lines)
    {
        int start = l[0];
        int end = l[1];
        
        for(int i = start; i < end; i++)
            diff[i + bias]++;
    }
    
    answer = std::count_if(diff.begin(), diff.end(), [](int elem){
        return elem > 1;
    });
    
    return answer;
}
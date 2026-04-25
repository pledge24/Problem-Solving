#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> arr) {
    int answer = 0;
    
    bool valid = true;
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[0].size(); j++)
        {
            if(arr[i][j] != arr[j][i])
                valid = false;
        }
    }
    
    answer = valid;
    return answer;
}
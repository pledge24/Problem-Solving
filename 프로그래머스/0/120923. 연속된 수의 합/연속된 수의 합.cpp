#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int start = total / num - ((num-1)/2);
    
    for(int i = start; i < start+num; i++)
        answer.push_back(i);
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    
    vector<int> lenCnt(31, 0);
    for(const string str : strArr)
    {
        int len = str.length();
        lenCnt[len]++;
    }
    
    answer = *max_element(lenCnt.begin(), lenCnt.end());
    
    return answer;
}
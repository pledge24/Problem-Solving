#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    vector<int> cnt(1000, 0);
    for(int elem : array)
    {
        cnt[elem]++;    
    }
    
    int freqNum = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    if(std::count(cnt.begin(), cnt.end(), cnt[freqNum]) > 1)
        freqNum = -1;
    
    answer = freqNum;
    
    return answer;
}
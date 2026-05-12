#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    
    int elems = s1.size() + s2.size();
    s1.insert(s1.end(), s2.begin(), s2.end());
    
    std::sort(s1.begin(), s1.end());
    s1.erase(std::unique(s1.begin(), s1.end()), s1.end());
        
    answer = elems - s1.size();
    
    return answer;
}
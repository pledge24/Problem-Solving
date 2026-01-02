#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    answer.resize(52);
    
    const int offset = 26;
    for(char c : my_string)
    {
        if(c < 'a')
            answer[c-'A']++;
        else
            answer[c-'a'+offset]++;
    }
    
    return answer;
}
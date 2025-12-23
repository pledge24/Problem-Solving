#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    for(int start = 0; start < my_string.size(); start++)
    {
        answer.push_back(my_string.substr(start));
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
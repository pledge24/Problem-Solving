#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = my_string;
    for(vector<int>& query : queries)
    {
        int start = query[0];
        int end = query[1] + 1;
        
        std::reverse(answer.begin() + start, answer.begin() + end);
        
        // cout << answer << '\n';
    }
    return answer;
}
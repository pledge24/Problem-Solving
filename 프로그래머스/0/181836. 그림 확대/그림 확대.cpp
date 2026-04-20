#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    
    for(const string& str : picture)
    {
        string tmp = "";
        for(char c : str)
        {
            int cnt = k;
            for(int i = 0; i < k; i++)
                tmp += c;
        }
        
        for(int i = 0; i < k; i++)
            answer.push_back(tmp);
    }
    
    return answer;
}
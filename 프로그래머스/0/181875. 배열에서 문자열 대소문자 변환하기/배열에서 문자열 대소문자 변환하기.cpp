#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    for(int i = 0; i < strArr.size(); i++)
    {
        string temp = "";
        for(char c : strArr[i])
            temp += i % 2 ? toupper(c) : tolower(c);
        
        answer.push_back(temp);
    }
    return answer;
}
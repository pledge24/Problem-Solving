#include <bits/stdc++.h>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    vector<string> v1 = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    string temp = "";
    for(char c : numbers)
    {
        temp += c;
        
        auto it = std::find(v1.begin(), v1.end(), temp);
        if(it != v1.end())
        {
            answer = answer*10 + (it - v1.begin());
            temp = "";
        }
    }
    
    auto it = std::find(v1.begin(), v1.end(), temp);
    if(it != v1.end())
    {
        answer = answer*10 + (it - v1.begin());
        temp = "";
    }
    
    return answer;
}
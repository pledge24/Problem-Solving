#include <bits/stdc++.h>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    set<string> s;
    for(int i = 0; i < my_string.length(); i++)
    {
        string suffix = my_string.substr(i);
        s.insert(suffix);
    }
    
    answer = s.find(is_suffix) != s.end();
    return answer;
}
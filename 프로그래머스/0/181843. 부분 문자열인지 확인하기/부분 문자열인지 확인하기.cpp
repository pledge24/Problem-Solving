#include <bits/stdc++.h>

using namespace std;

int solution(string my_string, string target) {
    int answer = 0;
    bool isPartial = false;
    for(int i = 0; i < my_string.length(); i++)
    {
        if(my_string.substr(i, target.length()) == target)
        {
            isPartial = true;
            break;
        }
    }
    
    answer = isPartial;
    
    return answer;
}
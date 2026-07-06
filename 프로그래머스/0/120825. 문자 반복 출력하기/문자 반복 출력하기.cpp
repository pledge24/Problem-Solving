#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    
    for(char c : my_string)
    {
        int x = n;
        while(x--) answer += c;
    }
    
    return answer;
}
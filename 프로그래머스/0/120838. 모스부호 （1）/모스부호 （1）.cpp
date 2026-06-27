#include <bits/stdc++.h>

using namespace std;

string solution(string letter) {
    string answer = "";
    
    vector<string> morse = { 
    ".-","-...","-.-.","-..",".","..-.",
    "--.","....","..",".---","-.-",".-..",
    "--","-.","---",".--.","--.-",".-.",
    "...","-","..-","...-",".--","-..-",
    "-.--","--.."
    };
    
    string temp = "";
    for(char c : letter)
    {
        if(c != ' ')
            temp += c;
        else
        {
            int idx = std::find(morse.begin(), morse.end(), temp) - morse.begin();
            answer += idx + 'a';
            temp = "";
        }
    }
    
    if(temp.length() > 0)
    {
        int idx = std::find(morse.begin(), morse.end(), temp) - morse.begin();
        answer += idx + 'a';
        temp = "";
    }
    
    return answer;
}
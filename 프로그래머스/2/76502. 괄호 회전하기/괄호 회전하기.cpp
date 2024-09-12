#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stack>

using namespace std;

bool iscorrect(string s){
    stack<char> s1;
    map<char, char> m1 = {{']', '['}, {')', '('}, {'}', '{'}};
    
    for(char c : s){      
        // 스택이 비어있는 경우.
        if(s1.empty()){
            if(c == '[' || c == '(' || c == '{'){
                s1.push(c);
                continue;
            }
            else{
                return false;
            }
        }
        
        char prev_c = s1.top();
        if(c == ']' || c == ')' || c == '}'){
            if(m1[c] == prev_c){ s1.pop(); continue; }
            else { return false; }            
        }
        else { s1.push(c); }
        
        
    }
    
    return s1.empty();
}

int solution(string s) {
    int answer = 0;
       
    for(int i = 0; i < s.length(); i++){
        char c = s[0];
        s+= c;
        s.erase(s.begin(),s.begin()+1);
        
        //cout << s << '\n';
        if(iscorrect(s)){
            //cout << "sssssss" << '\n';
            answer++;
        }
    }
    return answer;
}
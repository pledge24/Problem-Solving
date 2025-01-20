#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

enum Estate {NONE, ROUND, REC};

bool isBalanced(string& s){

    stack<Estate> _stack; _stack.push(Estate::NONE);
    for(char c : s){
        switch (c)
        {
        case '(':
            _stack.push(Estate::ROUND);
            break;
        case '[':
            _stack.push(Estate::REC);
            break;
        case ')':
            if(_stack.top() != ROUND)
                return false;
            else 
                _stack.pop();
            break;
        case ']':
            if(_stack.top() != REC)
                return false;
            else 
                _stack.pop();
            break;
        default:
            break;
        }
    }

    if(_stack.size() > 1) return false;
    
    return true;
}

int main(void){
    fastio;

    do{
        string s; getline(cin, s);

        if(s == ".")
            break;

        if(isBalanced(s)){
            cout << "yes" << '\n';
        }
        else{
            cout << "no" << '\n';
        }

    }while(true);
    
    return 0;
}
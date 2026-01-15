#include <bits/stdc++.h>

using namespace std;

// 여는 괄호와 닫는 괄호의 개수가 같다면, "균형잡힌 괄호 문자열"
// 여는 괄호와 닫는 결화의 짝이 맞다면, "올바른 괄호 문자열"
// 균형-- 이라면 올바른-- 치환가능
// 주어진 알고리즘으로 균형--을 올바른--으로 치환해라.

// w의 길이는 항상 2이상
// BBS -> 균형잡힌 괄호 문자열
string Correct(string w)
{
    if(w.length() == 0)
        return "";
    
    // 2. Find Unit BBS.
    int uEndPos = 0;
    bool uIsCbs = false;
    {
        int openCnt = 0;
        int closeCnt = 0;
        
        stack<char> stk;
        do
        {
            int curChar = w[uEndPos];
            if(curChar == '(')
                openCnt++;
            else if(curChar == ')')
                closeCnt++;
            
            if(!stk.empty())
            {
                char prevC = stk.top();
                if(prevC == '(' && curChar == ')')
                    stk.pop();
                else
                    stk.push(curChar);
            }
            else
                stk.push(curChar);
            
            uEndPos++;
            if(uEndPos == w.length())
                break;
            
        }while(openCnt != closeCnt);
            
        // check u is CBS
        uIsCbs = stk.empty() ? true : false;
    }
    
    string u = w.substr(0, uEndPos);
    string v = w.substr(uEndPos);
    
    if(uIsCbs)
    {
        return u + Correct(v);
    }
    
    string correctedV = "(" + Correct(v) + ")";
    if(u.length() < 2)
        return correctedV;
    
    for(int i = 1; i < u.length()-1; i++)
    {
        char c = u[i];
        correctedV += c == '(' ? ')' : '(';
    }
    
    return correctedV;
}

string solution(string p) {
    string answer = "";
    answer = Correct(p);
    return answer;
}
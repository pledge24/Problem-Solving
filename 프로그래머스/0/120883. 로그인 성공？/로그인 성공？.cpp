#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    
    if(std::find(db.begin(), db.end(), id_pw) != db.end())
        return "login";
    
    bool existId = false;
    for(const vector<string>& elem : db)
    {
        if(id_pw[0] == elem[0])
            existId= true;
    }
    
    if(existId)
        return "wrong pw";
    else
        return "fail";
    
    return answer;
}
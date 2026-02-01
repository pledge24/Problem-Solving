#include <bits/stdc++.h>

using namespace std;

// "가상의 닉네임?"
// 닉네임을 바꾸는 방법: 1) 채팅방을 나가서 바꿔온다. 2) 채팅방에서 바꾼다.
// 최종적으로 방을 개설한 사람이 보게 되는 형태는?
// record : "[cmd] [uid] [nickname]"
void Split(vector<string>& outRes, string s, string delimeter)
{
    int pos = 0;
    while(pos < s.length())
    {
        int nextDelimeterPos = s.find(delimeter, pos);
        if(nextDelimeterPos == string::npos)
        {
            nextDelimeterPos = s.length();
        }
        
        int len = nextDelimeterPos - pos;
        if(len > 0)
        {
            outRes.push_back(s.substr(pos, len));
        }
        
        pos = nextDelimeterPos + 1;
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string, string> m1;
    vector<pair<string, string>> inOutLog;
    for(string& s : record)
    {
        vector<string> splitted;
        Split(splitted, s, " ");
        
        const string& cmd = splitted[0];
        const string& uid = splitted[1];
        if(cmd == "Enter")
        {
            inOutLog.push_back(make_pair(cmd, uid));
            m1[uid] = splitted[2];
        }
        else if(cmd == "Leave")
        {
            inOutLog.push_back(make_pair(cmd, uid));
        }
        else if(cmd == "Change")
        {
            m1[uid] = splitted[2];
        }
        
        // for(string x : splitted)
        //     cout << x << ' ';
        // cout << '\n';
    }
    
    for(auto& p : inOutLog)
    {
        const string& cmd = p.first;
        const string& uid = p.second;
        const string& nickname = m1[uid];
        
        if(cmd == "Enter")
        {
            answer.push_back(nickname + "님이 들어왔습니다.");
        }
        else if(cmd == "Leave")
        {
            answer.push_back(nickname + "님이 나갔습니다.");
        }
        
    }
    
    return answer;
}
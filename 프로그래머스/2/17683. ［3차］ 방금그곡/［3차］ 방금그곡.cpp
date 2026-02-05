#include <bits/stdc++.h>

using namespace std;

void Split(string& s, vector<string>& splitted, string delimeter)
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
            splitted.push_back(s.substr(pos, len));
        }
        
        pos = nextDelimeterPos + delimeter.size();
    }
}

string Normalize(string& s)
{
    string res = "";
    int len = s.length();
    
    for(int i = 0; i < len; i++)
    {
        char c = s[i];
        if(i + 1 < len && s[i+1] == '#')
        {
            res += tolower(c);
            i++;
        }
        else
        {
            res += c;
        }
    }
    
    return res;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    struct musicData
    {
        string title = "";
        int playTime = 0;
    };
    
    m = Normalize(m);
    cout << m << '\n';
    
    vector<musicData> candidate;
    for(int i = 0; i < musicinfos.size(); i++)
    {
        string& s = musicinfos[i];
            
        vector<string> splitted;
        Split(s, splitted, ",");
        
        string& startTime = splitted[0];
        string& endTime = splitted[1];
        string& title = splitted[2];
        string note = Normalize(splitted[3]);
        
        // Get PlayTime
        int playTime = 0;
        {
            // Tips: 크기가 일정한 경우, 그냥 substr만 써도 충분. 코드를 간결화 효과 챙기자
            int sHH = stoi(startTime.substr(0, 2));
            int sMM = stoi(startTime.substr(3, 2));
            int eHH = stoi(endTime.substr(0, 2));
            int eMM = stoi(endTime.substr(3, 2));
            
            playTime = (eHH - sHH)*60 + eMM - sMM;
        }
        
        string played = "";
        for(int i = 0; i < playTime; i++)
        {
            played += note[i % note.length()];
        }
        
        if(played.find(m) != string::npos)
        {
            musicData md = {title, playTime};
            candidate.push_back(md); 
            
            // printf("title: %s, playTime: %d, idx: %d\n", md.title.c_str(), md.playTime, md.idx);
        }
    }
    
    if(candidate.size() == 0)
        answer = "(None)";
    else
    {
        musicData bestMd = candidate[0];
        for(int i = 1; i < candidate.size(); i++)
        {
            musicData& md = candidate[i];
            if(bestMd.playTime < md.playTime)
            {
                bestMd = md;
            }
        }
        answer = bestMd.title;
    }
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

// '방금그곡' 서비스.
// - 고객이 기억한 멜로디를 소스로 사용해 음악을 찾는다.
// - 한 음악을 반복 재생 -> 기억한 멜로디의 시작이 음악의 시작 부분이 아닐 수 있음.
// - 한 음악을 중간에 끊음 -> 찾은 곡에도 있는 멜로디지만, 들은 곡은 아닐 수 있음.
// So, 기억한 멜로디를 1) 재생 시간과 2) 제공된 악보를 직접 보며 비교하려고 한다.

// 서비스는 1) 구간 ([재생 시작, 끝남]), 2) 제목, 3) 악보 제공
// 각 음은 1분에 1개씩 재생됨. 
// - 항상 처음부터 재생
// - 재생 길이 > 음악 길이라면, 반복 재생으로 간주
// - 재생 길이 < 음악 길이라면, 처음부터 재생 시간만큼 재생
// - 음악은 00:00을 초과하지 않는다.(HH:MM)
// - 후보가 여러개라면 "라디오에서 재생된 시간이 제일 긴 음악 제목"을 반환.
// - 재생된 시간도 같다면, 먼저 입력된 음악 제목을 반환

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

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    struct musicData
    {
        string title = "";
        int playTime = 0;
    };
    
    string mTemp = "";
    for(int i = 0; i < m.length(); i++)
    {
        char c = m[i];
        if(isalpha(c) == false)
            mTemp[mTemp.length()-1]++;
        else
            mTemp += char((c - 'A') * 2 + 'A');
    }
    
    std::swap(mTemp, m);
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
        string& note = splitted[3];
        
        // Get PlayTime
        int playTime = 0;
        {
            vector<string> sTime;
            vector<string> eTime;
            Split(startTime, sTime, ":");
            Split(endTime, eTime, ":");

            int sHH = stoi(sTime[0]);
            int sMM = stoi(sTime[1]);
            int eHH = stoi(eTime[0]);
            int eMM = stoi(eTime[1]);
            
            playTime = (eHH - sHH)*60 + eMM - sMM;
        }
        
        string noteX = "";
        for(int i = 0; i < note.length(); i++)
        {
            char c = note[i];
            if(isalpha(c) == false)
                noteX[noteX.length()-1]++;
            else
                noteX += char((c - 'A') * 2 + 'A');
        }
        
        string temp = "";
        int len = 0;
        int curIdx = 0;
        while(len < playTime)
        {
            temp += char((note[curIdx] - 'A') * 2 + 'A');
            
            // Check
            if(isalpha(note.substr(curIdx, 2).back()) == false)
            {
                temp[temp.length()-1]++;
                curIdx = (curIdx + 1) % note.length();
            }
            
            // Update
            len++;
            curIdx = (curIdx + 1) % note.length();
        }
        
        // cout << "noteX: " << noteX << '\n';
        // cout << "temp: " << temp << '\n';
        
        if(temp.find(m) != string::npos)
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
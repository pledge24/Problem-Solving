#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

void Split(vector<string>& splitted, string str, string delimeter)
{
    int pos = 0;
    
    while(pos < str.length())
    {
        int nextDelimeterPos = str.find(delimeter, pos);
        if(nextDelimeterPos == string::npos)
            nextDelimeterPos = str.length();
        
        int len = nextDelimeterPos - pos;
        if(len > 0)
        {
            splitted.push_back(str.substr(pos, len));
        }
        
        pos = nextDelimeterPos + delimeter.length();
    }
}

int solution(vector<string> lines) {
    int answer = 0;
    
    vector<pair<int64, int64>> timeLine; // <startTime, endTime>
    for(string l : lines)
    {
        vector<string> splitted;
        Split(splitted, l, " ");
        
        // for(string s : splitted)
        // {
        //     cout << s << ' ';
        // }
        // cout << '\n';
        
        vector<string> responseTime;
        Split(responseTime, splitted[1] , ":");
        int64 endTimeMs = 0;
        {
            int64 hh = stoll(responseTime[0]);
            int64 mm = stoll(responseTime[1]);
            int64 ss = stoll(responseTime[2].substr(0, 2));
            int64 ms = stoll(responseTime[2].substr(3, 3));
            
            // printf("%d %d %d %f\n", hh, mm, ss, ms);
            endTimeMs = (hh*60*60 + mm*60 + ss)*1000 + ms;
            // cout << "endTime: " << endTime << '\n';
        }
        
        string th = "";
        for(char c : splitted[2])
        {
            if(isdigit(c))
                th += c;
        }
        
        while(th.length() < 4)
            th += "0";
        
        int64 startTimeMs = endTimeMs - (stoll(th) - 1);
        
        // cout << "th: " << th << '\n';
        // cout << startTimeMs << " " << endTimeMs << '\n';
        timeLine.push_back(make_pair(startTimeMs, endTimeMs));  // endTime으로 정렬되어 있음.
    }
    
    for(int i = 0; i < timeLine.size(); i++)
    {
        int64 rngBegin = timeLine[i].second;
        int64 rngEnd = rngBegin + 1000 - 1;
        
        // cout << rngBegin << " " << rngEnd << '\n';
        
        int cnt = 0;
        for(int j = 0; j < timeLine.size(); j++)
        {
            int64 s = timeLine[j].first;
            int64 e = timeLine[j].second;
            
            // cout << "s: " << s << " e: " << e << '\n';
            if(e < rngBegin || rngEnd < s)
                continue;
            
            // cout << (rngBegin <= e) << "||" << (s <= rngEnd) << '\n';
            // cout << "Pass" << '\n';
            cnt++;
        }
        
        // cout << cnt << '\n';
        answer = max(answer, cnt);
    }
    
    
    return answer;
}
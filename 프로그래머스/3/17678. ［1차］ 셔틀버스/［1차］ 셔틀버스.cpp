#include <bits/stdc++.h>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> busTime;
    
    for(int i = 0; i < n; i++)
    {
        int hh = 9 + (t*i) / 60;
        int mm = (t*i) % 60;
        busTime.push_back(hh*100 + mm);
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(const string& tt : timetable)
    {
        int hh = stoi(tt.substr(0, 2));
        int mm = stoi(tt.substr(3, 2));
        
        pq.push(hh*100 + mm);
    }
    
    int curTime = 0;
    for(int i = 0; i < n; i++)
    {
        int t = busTime[i];
        for(int j = 0; j < m-1; j++)
        {
            if(pq.empty())  break;
            
            int ct = pq.top();
            if(ct > t)  break;
            pq.pop();
        }
        
        curTime = t;
        if(!pq.empty() && pq.top() <= t)
        {
            int hh = pq.top() / 100;
            int mm = pq.top() % 100;
        
            mm--;
            if(mm < 0)
            {
                hh--;
                mm += 60;
            }
            
            curTime = hh*100 + mm;
            pq.pop();
        }
        
        // cout << curTime << '\n';
    }
        
    string hh = to_string(curTime / 100);
    string mm = to_string(curTime % 100);
    
    if(hh.length() < 2)
        hh = "0" + hh;
    if(mm.length() < 2)
        mm = "0" + mm;
    
    answer = hh + ":" + mm;
    
    return answer;
}
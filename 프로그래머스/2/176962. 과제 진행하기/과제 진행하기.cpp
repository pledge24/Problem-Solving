#include <bits/stdc++.h>

using namespace std;

// 시간이 된 과제가 항상 1순위
// 다음 과제까지 여유가 있다면 남은 과제 진행가능
// => 최근에 시작한 과제부터 처리한다.
struct JobData
{
    string name = "";
    int start;
    int playTime = 0;
};

struct cmp
{
    bool operator()(const JobData& j1, const JobData& j2) const
    {
        return j1.start > j2.start;
    }
};

int GetTime(const string& timeStr)
{
    int hh = stoi(timeStr.substr(0, 2));
    int mm = stoi(timeStr.substr(3, 2));
    
    return hh*60 + mm;
}

void DoStopJobs(int& curTime, int start, stack<JobData>& stopJobs, vector<string>& answer)
{
    while(!stopJobs.empty())
    {
        JobData j = stopJobs.top(); stopJobs.pop();
        int endTime = curTime + j.playTime;
        
        if(endTime > start)
        {
            int leftTime = endTime - start;
            j.playTime = leftTime;
            stopJobs.push(j);
            
            curTime = start;
            return;
        }
        
        answer.push_back(j.name);
        curTime = endTime; 
    }
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<JobData, vector<JobData>, cmp> pq;
    
    // input
    for(vector<string>& p : plans)
    {
        JobData jobData;
        {
            jobData.name = p[0];
            jobData.start = GetTime(p[1]);
            jobData.playTime = stoi(p[2]);
        }
        
        pq.push(jobData);
    }
    
    // Do job
    stack<JobData> stopJobs;
    int curTime = 0;
    while(!pq.empty())
    {
        JobData j = pq.top(); pq.pop();
        int start = j.start;
        
        if(curTime < start)
        {
            DoStopJobs(curTime, start, stopJobs, answer);
        }
        curTime = start;
        
        if(pq.empty())
        {
            answer.push_back(j.name);
            break;
        }
        
        int nextStart = pq.top().start;
        int endTime = curTime + j.playTime;
        if(endTime > nextStart)
        {
            int leftTime = endTime - nextStart;
            j.playTime = leftTime;
            stopJobs.push(j);
            
            curTime = nextStart;
        }
        else
        {
            answer.push_back(j.name);
            curTime = endTime;
        }
    }
    
    while(!stopJobs.empty())
    {
        JobData j = stopJobs.top(); stopJobs.pop();
        answer.push_back(j.name);
    }
    
    return answer;
}
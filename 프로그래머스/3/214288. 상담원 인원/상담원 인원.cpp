#include <bits/stdc++.h>

#define INF 1'000'000'000

using namespace std;
using TaskList = vector<pair<int, int>>; // startTime, period
using PQ = priority_queue<int, vector<int>, greater<int>>; // 대기 시간 우선순위 큐

// 계산한다. 뭘? 1~maxN 명이 배치되었을때의 최소 대기 시간을...
void calcMinTime(vector<int>& v1, TaskList& taskList, int maxN){
    for(int i = 1; i <= maxN; i++){
        PQ pq;
        for(int j = 0; j < i; j++) pq.push(0);
        
        // 상담을 하나씩 넣으면서, 총 대기 시간 계산
        int totalWaitTime = 0;
        for(auto elem : taskList){
            int endTime = pq.top(); pq.pop();
            
            // startTime이 뒤에 있으면 대기시간은 0.
            totalWaitTime += endTime <= elem.first ? 0 : endTime - elem.first;
            pq.push(max(endTime, elem.first) + elem.second);
        }
        
        v1[i] = totalWaitTime;
    }
}

void DfsUtil(vector<vector<int>>& minWaitTimeList, int n, int k, vector<int>& sequnce, int idx, int& minTime){
    int maxN = n - k + 1;
    
    // 종료 조건.
    if(idx > k){
        // for(auto elem : sequnce)
        //     cout << elem << " ";
        // cout << '\n';
        
        int totalWaitTime = 0;
        int totalMentors = 0;
        for(int i = 1; i < sequnce.size(); i++){
            int mentors = sequnce[i];
            totalMentors += mentors;
            
            if(totalMentors > n)
                return;
            
            totalWaitTime += minWaitTimeList[i][mentors];
        }
        
        // cout << "totalWaitTime: " << totalWaitTime << '\n';
        
        minTime = min(minTime, totalWaitTime);
        
        return; 
    }
    
    for(int i = 1; i <= maxN; i++){
        sequnce.push_back(i);
        DfsUtil(minWaitTimeList, n, k, sequnce, idx+1, minTime);
        sequnce.pop_back();
    }
    
    return;
}

int Dfs(vector<vector<int>>& minWaitTimeList, int n, int k){
    int minTime = INF;
    
    int nextIdx = 1;
    vector<int> sequnce(1); // 부스 멘토 배치 정보
    DfsUtil(minWaitTimeList, n/* desired */, k, sequnce, nextIdx, minTime);
    
    return minTime;
}

// 멘토 수: n명
// 상담 유형: k개
int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    int maxN = n - k + 1;
    
    vector<TaskList> taskLists(k+1);
    
    // 각 상담을 유형에 맞게 따로 저장한다.
    for(auto task : reqs){
        int taskType = task[2];
        
        int startTime = task[0];
        int period = task[1];
        
        taskLists[taskType].push_back(make_pair(startTime, period));
    }
    
    // 각 상담 유형에 따른 maxN개 까지의 최소 대기 시간?
    vector<vector<int>> minWaitTimeList(k+1, vector<int>(maxN + 1));
    for(int i = 1; i <= k; i++){
        vector<int>& v1 = minWaitTimeList[i];
        
        calcMinTime(v1, taskLists[i], maxN);
        
        // for(auto elem : v1)
        //     cout << elem << " ";
        // cout << '\n';
    }
    
    // 각 부스에 배치한 멘토 수의 합이 N이 되는 모든 경우의 수를 구한다.(DFS)
    answer = Dfs(minWaitTimeList, n, k);
    
    return answer;
}
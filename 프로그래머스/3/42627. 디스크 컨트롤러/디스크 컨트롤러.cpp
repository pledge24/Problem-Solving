#include <bits/stdc++.h>
using namespace std;

struct JobData {
    int requestTime;
    int processTime;
};

struct Cmp {
    bool operator()(const JobData& j1, const JobData& j2) {
        // 소요 시간이 짧은 것이 우선순위가 높아야 함 (min-heap)
        return j1.processTime > j2.processTime;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int jobIdx = 0;
    int curTime = 0;
    int totalResponseTime = 0;

    // 1. 요청 시간 순으로 원본 데이터 정렬
    sort(jobs.begin(), jobs.end());

    // 현재 실행 가능한 작업을 담는 PQ (소요 시간 짧은 순)
    priority_queue<JobData, vector<JobData>, Cmp> pq;

    while (jobIdx < jobs.size() || !pq.empty()) {
        
        // 2. 현재 시간까지 요청된 모든 작업을 PQ에 삽입
        while (jobIdx < jobs.size() && jobs[jobIdx][0] <= curTime) {
            pq.push({jobs[jobIdx][0], jobs[jobIdx][1]});
            jobIdx++;
        }

        if (!pq.empty()) {
            // 3. 실행 가능한 작업 중 가장 짧은 것 처리
            JobData jd = pq.top();
            pq.pop();
            
            curTime += jd.processTime;
            totalResponseTime += (curTime - jd.requestTime);
        } else {
            // 4. 현재 처리할 수 있는 작업이 없다면 다음 작업의 요청 시간으로 이동
            curTime = jobs[jobIdx][0];
        }
    }

    return totalResponseTime / jobs.size();
}
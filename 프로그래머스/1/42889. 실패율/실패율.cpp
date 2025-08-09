#include <bits/stdc++.h>

using namespace std;

// 실패율을 구해라?
// -> 클리어 X 플레이어 수 / 진입 플레이어 수
// 실패율이 높은 스테이지부터 내림차순

// N: 스테이지 개수(1 <= N <= 500)
// stages: 사용자가 도전중인 스테이지가 들어있음(=사용자수) (1 <= stages <= 200,000)
// stage 1~N+1
// N+1은 마지막 스테이지를 깬(N번째) 사용자를 의미
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    // 각 스테이지에 머물고 있는 유저 집계(m1)
    map<int, int> m1; // <stageNo, users>
    for(int i = 0; i < stages.size(); i++){
        int stageNo = stages[i];
        m1[stageNo]++;
    }
    
    // 스테이지 오름차순 정렬
    sort(stages.begin(), stages.end());
    
    struct cmp{
        bool operator() (pair<float, int> p1, pair<float, int> p2){
            if(p1.first == p2.first)
                return p1.second > p2.second;

            return p1.first < p2.first;
        }
    };
    
    priority_queue<pair<float, int>, vector<pair<float, int>>, cmp> pq;
    
    
    // <실패율, 스테이지 번호> 계산해서 pq에 push
    int total_users = stages.size();
    for(int i = 1; i <= N; i++){
        int notReachUsers = lower_bound(stages.begin(), stages.end(), i) - stages.begin();
        
        float fail_rate = m1[i] > 0 ? (float)m1[i] / (total_users - notReachUsers) : .0f;
        pq.push(make_pair(fail_rate, i));
    }
    
    
    while(!pq.empty()){
        // cout << pq.top().first << " " << pq.top().second << '\n';
        answer.push_back(pq.top().second); pq.pop();
    }
    
    return answer;
}
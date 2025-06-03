#include <iostream>
#include <map>
#include <vector>
#include <queue>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct finalData{
    int totalScores = 0;
    int submitCnt = 0;
    int lastTime = 0;
    int teamId = -1;

    bool operator<(const finalData& other) const {
        if(totalScores != other.totalScores)
            return totalScores < other.totalScores;
        
        if(submitCnt != other.submitCnt)
            return submitCnt > other.submitCnt;

        return lastTime > other.lastTime;
    }
};

using Scores = map<int, int>;

void startTest(){
    int N, K, T, M; cin >> N >> M >> T >> M;

    // 점수는 가장 높은거
    // 제출 시간과 횟수는 따로 관리
    vector<finalData> v1(N+1);
    vector<Scores> scores(N+1);
    for(int i = 0; i < M; i++){
        int teamId, problemId, score;
        cin >> teamId >> problemId >> score;

        Scores& curTeam = scores[teamId];
        curTeam[problemId] = max(curTeam[problemId], score);
        v1[teamId].submitCnt++;
        v1[teamId].lastTime = i;
        v1[teamId].teamId = teamId;
    }

    // 총 점수 계산
    priority_queue<finalData> pq;
    for(int i = 1; i <= N; i++){
        int totalScores = 0;
        for(auto elem : scores[i]){
            totalScores += elem.second;
        }

        v1[i].totalScores = totalScores;
        pq.push(v1[i]);
    }

    int myRank = 1;
    while(!pq.empty()){
        finalData cur = pq.top(); pq.pop();
        if(cur.teamId == T)
            break;
        
        myRank++;
    }

    cout << myRank << '\n';
    
    return;
}

int main(void){
    fastio;
    int T; cin >> T;
    for(int i = 0; i < T; i++){
        startTest();
    }

    return 0;
}
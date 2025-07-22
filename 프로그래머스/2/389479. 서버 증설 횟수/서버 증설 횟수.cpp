#include <bits/stdc++.h>

using namespace std;

// 서버 한 대는 m 명을 수용할 수 있다.
// 증설한 서버는 k시간동안 운영된다.
// => 서버 증설 최소 횟수는? (서버는 인원수가 딱뎀일때 증설한다.)

// players : 24시간 기준 1시간 단위의 접속 인원수
// m : 서버 한 대의 최대 수용 인원
// k : 서버 한 대의 최대 운영 시간

// 현재 필요한 서버 개수 vs 이미 운영중인 서버 대수
// -> 충분하면 pass, 적으면 증설
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    queue<int> extraServer; // terminateTime
    for(int i = 0; i < players.size();/* 24h */ i++){
        int users = players[i];
        
        // 이미 종료된 서버는 제거.
        while(extraServer.empty() == false && extraServer.front() <= i)
            extraServer.pop();
        
        // 한 대로도 수용 가능하면 pass.
        if(users < m)
            continue;
        
        int overN = users - m;
        int needServerN = (overN / m) + 1;
        
        // 이미 충분히 증설되어 있으면 pass, 아니면 추가 증설.
        if(needServerN <= extraServer.size())
            continue;
        
        answer += needServerN - extraServer.size();
        int scaleN = needServerN - extraServer.size();
        for(int ex = 0; ex < scaleN; ex++)
            extraServer.push(i + k);
    }
    
    return answer;
}
// 12 20~22 26 28
#include <bits/stdc++.h>

using namespace std;

// 보유한 병사 n명으로 적의 공격을 "순서대로" 막아라.
// 적의 수만큼 병사 수가 줄어든다.
// 무적권을 사용하면 병사 수가 줄지 않는다. (최대 k번 사용가능)
// 도달할 수 있는 최대 라운드는?

// => 충분히 버틸 수 있으면서도, 가장 적의 수가 많을 때 "무적권"을 사용한다.
// 이동을 하면서 지금까지 중 가장 많은 적의 수를 빼고 "무적권"을 사용한다.
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    int accuEnemies = 0;
    int leftK = k;
    priority_queue<int> pq; // 라운드에서 만난 적의 수(내림차순 정렬)
    for(int round = 0; round < enemy.size(); round++){
        // 현재 라운드 적의 수 추가.
        pq.push(enemy[round]);
        accuEnemies += enemy[round];
        
        // 적의 수 초과시, 무적권 사용
        while(n < accuEnemies && leftK > 0 && pq.empty() == false){
            int maxEnemies = pq.top(); pq.pop();
            accuEnemies -= maxEnemies;
            leftK--;
        }
        
        // cout << "accuEnemies: " << accuEnemies << '\n';
        
        // 무적권을 썼는데도 적의 수가 많다면 라운드 종료
        if(n < accuEnemies){
            break;
        } 
        
        // 클리어로 인한 라운드 수 증가
        answer++;
    }
    
    return answer;
}
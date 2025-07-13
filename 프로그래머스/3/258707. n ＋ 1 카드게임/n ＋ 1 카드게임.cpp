#include <bits/stdc++.h>

using namespace std;

// 1~n 숫자 카드, 동전 coin개
// 1) 시작: n/3장의 카드와 coin개를 가지고 시작.
// 2) 카드 뽑기: 라운드마다 카드 2장을 뽑는다. 카드 뭉치에 카드가 0장이면 게임은 종료됨.
// 3) 카드 선택: 뽑은 카드는 카드 수만큼 동전을 소모하여 가질 수 있음
// 4) 카드 내기: 카드를 2장의 합이 n+1이면 낼 수 있음. 낼 수 없다면 그대로 종료.
// 가능한 최대 라운드 수는? -> 가장 오래 살아남을 수 있는 전략은?

// +) 카드는 card에 적힌 순서대로 뽑는다.

// 아이디어
// 현재 라운드에서 짝이 완성되는 카드를 가져간다.
// 코인은 가지고 있지 않은 카드 개수만큼 지불한다.
// 코인이 부족하면 집지 않는다.

// 완성한 쌍이 있으면, 쌍을 쓰고 라운드를 넘어간다.
// 완성된 쌍이 없다면, 1코스트 쌍을 보고 2코스트 쌍을 본다.
// 있으면 가져다 쓴다. 돈이 없으면 그대로 디진다.
int solution(int coin, vector<int> cards) {
    int answer = 0;
    int N = cards.size();
    
    int initCards = N / 3;
    
    // 짝 카드를 만날 수 있는 라운드를 저장한 배열. [카드 숫자] = 라운드 번호
    vector<int> pairingRound(N+1);
    for(int i = 0; i < cards.size(); i++){
        int cardNum = cards[i];
        int otherNum = (N+1) - cards[i];
        
        if(i < initCards){
            pairingRound[cardNum] = 0;
            pairingRound[otherNum] = 0;
            
            continue;
        }
        
        int round = (i - initCards) / 2 + 1;
        pairingRound[cardNum] = round;
        pairingRound[otherNum] = round;
    }
    
    for(auto elem : pairingRound)
        cout << elem << ' ';
    cout << '\n';
    
    int pairs = 0;
    
    priority_queue<int, vector<int>, greater<int>> one_pq; // 1 코스트 페어
    priority_queue<int, vector<int>, greater<int>> two_pq; // 2 코스트 페어
    
    vector<bool> haveCard(N+1);
    // 초기 카드 세팅
    int initPairs = 0;
    for(int i = 0; i < initCards; i++){
        int num = cards[i];
              
        haveCard[num] = true;
        
        if(pairingRound[num] == 0)
            initPairs++;
        else
            one_pq.push(pairingRound[num]);
    }
    
    pairs = initPairs / 2;
    
    // cout << "Init Pairs: " << pairs << '\n';
    
    int curRound = 1;
    for(int i = initCards; i < cards.size(); i += 2){      
        int num1 = cards[i];
        int num2 = cards[i+1];
        
        int otherNum1 = (N+1) - cards[i];
        int otherNum2 = (N+1) - cards[i+1];
    
        haveCard[num1] = true;
        haveCard[num2] = true;
        
        // 현재 라운드의 두 수의 합이 n+1이다 -> 지금 라운드에서 만들어진다.
        if(num1 + num2 == N+1){
            two_pq.push(pairingRound[num1]);
        }
        // 현재 라운드에서 추가되는 쌍을 각 코스트 pq에 넣는다.
        else {
            if(haveCard[otherNum1] == false)
                two_pq.push(pairingRound[num1]);
            if(haveCard[otherNum2] == false)
                two_pq.push(pairingRound[num2]);
        }
             
        // 다음 라운드 진출 확인
        if(pairs == 0){
            // pq에서 하나 가져온다.
            int needCost = -1;
            if(!one_pq.empty() && curRound >= one_pq.top()){
                // cout << "curRound: " << curRound << " One Cost Made Round: " << one_pq.top() << '\n';
                needCost = 1;
                one_pq.pop();
            }
            else if(!two_pq.empty() && curRound >= two_pq.top()){
                // cout << "curRound: " << curRound << " Two Cost Made Round: " << two_pq.top() << '\n';
                needCost = 2;
                two_pq.pop();
            }
            
            if(needCost == -1 || coin < needCost)
                break;
            
            coin -= needCost;
        }
        else{
            pairs--;
        }
        
        curRound++;
    }
    
    answer = curRound;
    
    return answer;
}
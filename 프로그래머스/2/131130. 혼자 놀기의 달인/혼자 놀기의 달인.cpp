#include <bits/stdc++.h>

using namespace std;

// 2이상 100이하의 자연수 X선택
// X이하의 카드들을 준비
// 각 카드를 작은 상자 하나씩 넣는다.(상자는 랜덤 정렬)
// 상자는 순서대로 1부터 번호 부여
// 상자 하나 선택 -> 카드 확인 -> 카드 번호 상자 확인 -> 반복 => 1번 상자 그룹
// 1번 그룹 * 2번 그룹 = 게임의 점수
// 최고 점수는?
// 최대 상자 개수는 100개
// 100*100
int GetGroupSize(vector<int>& cards, vector<bool>& visited, int num)
{
    int cnt = 0;
    while(visited[num] == false)
    {
        cnt++;
        visited[num] = true;
        
        num = cards[num-1];
    }
    
    return cnt;
}

int solution(vector<int> cards) {
    int answer = 0;
    
    vector<bool> visited(cards.size()+1);
    priority_queue<int> pq;
    for(int elem : cards)
    {
        if(visited[elem] == false)
        {
            int cnt = GetGroupSize(cards, visited, elem);
            pq.push(cnt);
        }
    }
    
    if(pq.size() >= 2)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        answer = a*b;
    }
    else
    {
        answer = 0;
    }
    
    
    return answer;
}
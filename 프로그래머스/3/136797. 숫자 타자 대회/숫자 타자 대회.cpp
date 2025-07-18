#include <bits/stdc++.h>

using namespace std;
using Pos = pair<int, int>;

pair<int, int> numToPos (int num){
    Pos res;
    
    if(num == 0)
        res = make_pair(3, 1);
    else
        res = make_pair((num-1) / 3, (num-1) % 3);
    
    return res;
}

// int PosToNum (Pos& pos){
//     int res;
    
//     if(pos.first == 3)
//         res = 0;
//     else
//         res = pos.first*3 + pos.second + 1;
    
//     return res;
// }

int calcCost(int num1, int num2){
    Pos src = numToPos(num1);
    Pos dst = numToPos(num2);
    
    if(src == dst)
        return 1;
    
    int diagonal = min(abs(src.first - dst.first), abs(src.second - dst.second));
    int horizonal = abs(src.second - dst.second) - diagonal;
    int vertical = abs(src.first - dst.first) - diagonal;
    
    int cost = diagonal*3 + horizonal*2 + vertical*2;
    
    return cost;
}

// 두 손가락 키패드 위치, 다음 숫자, DP값
void MoveFinger(Pos fingerNum, int nextNum, map<Pos, int>& m1, int prevCost){
    
    // leftMove
    if (nextNum != fingerNum.second){
        Pos nextFingerNum = make_pair(nextNum, fingerNum.second);
        int cost = prevCost + calcCost(fingerNum.first, nextNum);
        
        if(nextFingerNum.first > nextFingerNum.second)
            swap(nextFingerNum.first, nextFingerNum.second);
        
        if(m1[nextFingerNum] > 0)
            m1[nextFingerNum] = min(m1[nextFingerNum], cost);
        else
            m1[nextFingerNum] = cost;
    }
    
    // rightMove
    if (fingerNum.first != nextNum){
        Pos nextFingerNum = make_pair(fingerNum.first, nextNum);
        int cost = prevCost + calcCost(fingerNum.second, nextNum);
        
        if(nextFingerNum.first > nextFingerNum.second)
            swap(nextFingerNum.first, nextFingerNum.second);
        
        if(m1[nextFingerNum] > 0)
            m1[nextFingerNum] = min(m1[nextFingerNum], cost);
        else
            m1[nextFingerNum] = cost;
    }
    
}

int solution(string numbers) {
    int answer = 0;
    int N = numbers.length();
    
    // 매 반복 최대 55개(10C2)가 존재
    vector<map<Pos, int>> DP(N+1); // Pos는 키패드 숫자.
    
    DP[0][make_pair(4, 6)] = 0;
    for(int i = 1; i <= N; i++){
        int nextNum = numbers[i-1] - '0';
        
        for(auto elem : DP[i-1]){    
            MoveFinger(elem.first, nextNum, DP[i], elem.second);      
        }
    }
    
    for(int i = 0; i <= N; i++){
        for(auto elem : DP[i]){    
            Pos pos = elem.first;
            int cost = elem.second;
            
            // cout << "Pos: " << pos.first << " " << pos.second << " cost: " << cost << '\n';
        }
        // cout << '\n';
    }
    
    pair<Pos, int> minPair = *min_element(DP[N].begin(), DP[N].end(), [](pair<Pos, int> p1, pair<Pos, int> p2){
        return p1.second < p2.second;
    });

    answer = minPair.second;
    
    return answer;
}
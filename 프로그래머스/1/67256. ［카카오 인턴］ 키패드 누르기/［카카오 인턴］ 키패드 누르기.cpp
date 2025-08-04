#include <bits/stdc++.h>

using namespace std;
using Pos = pair<int, int>;

// 1) 1, 4, 7은 왼쪽 손이 누름
// 2) 3, 6, 9는 오른쪽 손이 누름
// 3) 2, 5, 8, 0은 가까운 손이 누름(거리가 같으면 XXX잡이는 XXX손을 사용)

vector<int> leftNum = {1, 4, 7};
vector<int> rightNum = {3, 6, 9};
vector<int> middleNum = {2, 5, 8, 0};

int getDistance(Pos p1, Pos p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

// => 번호를 누른 순서는?
string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    Pos lastLeft = make_pair(3, 0);
    Pos lastRight = make_pair(3, 2);
    bool isRightHand = hand == "right";
    
    for(int num : numbers){
        
        // 왼쪽 확인.
        if(find(leftNum.begin(), leftNum.end(), num) != leftNum.end()){
            int r = (num-1) / 3;
            int c = (num-1) % 3;
            lastLeft = make_pair(r, c);
            
            answer += 'L';
            continue;
        }
        
        // 오른쪽 확인.
        if(find(rightNum.begin(), rightNum.end(), num) != rightNum.end()){
            int r = (num-1) / 3;
            int c = (num-1) % 3;
            lastRight = make_pair(r, c);
            
            answer += 'R';
            continue;
        }
        
        // 중앙 확인.
        if(find(middleNum.begin(), middleNum.end(), num) != middleNum.end()){
            int r = num != 0 ? (num-1) / 3 : 3;
            int c = num != 0 ? (num-1) % 3 : 1;
            
            int d1 = getDistance(lastLeft, make_pair(r, c));
            int d2 = getDistance(lastRight, make_pair(r, c));
            
            if(d1 == d2){
                if(isRightHand)
                    lastRight = make_pair(r, c);
                else
                    lastLeft = make_pair(r, c);
                
                answer += isRightHand ? "R" : "L";
            }
            else{
                if(d1 > d2)
                    lastRight = make_pair(r, c);
                else
                    lastLeft = make_pair(r, c);
                
                answer += d1 > d2 ? "R" : "L";
            }
            
            continue;
        }
    }
    
    return answer;
}
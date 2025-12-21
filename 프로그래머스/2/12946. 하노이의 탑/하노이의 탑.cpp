#include <bits/stdc++.h>

using namespace std;

const int LEFT = 0;
const int CENTER = 1;
const int RIGHT = 2;

void DnC(int n, int src, int dst, int bypass, vector<vector<int>>& answer)
{
    if(n == 1)
    {
        answer.push_back({src+1, dst+1});
        return;
    }
    
    // 1. n-1 길이의 탑을 byPass에 옮긴다.
    DnC(n-1, src, bypass, dst, answer);
        
    // 2. 가장 아래에 있는 원판을 목적지에 옮긴다.
    DnC(1, src, dst, bypass, answer);
    
    // 3. n-1 길이의 탑을 목적지에 옮긴다.
    DnC(n-1, bypass, dst, src, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    // n 길이의 탑 -> 가장 아래에 있는 원판 + n-1 길이의 탑
    DnC(n, LEFT, RIGHT, CENTER, answer);
    
    return answer;
}
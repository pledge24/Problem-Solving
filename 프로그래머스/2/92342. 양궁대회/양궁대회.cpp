#include <bits/stdc++.h>

using namespace std;

// 라이언 vs 어피치 (우승자인 라이언에서 불리한 룰 적용)
// 중앙 10점 ~ 바깥쪽 0점
// 같은 점수에 대해 많이 꽂은 플레이어가 해당 점수를 가져감(같으면 어피치)
// 점수가 같으면 어피치
// 최고로 많은 차이를 내려고 한다면, 라이언은 n발의 화살을 어떻게 맞추어야하는가?
// (우승 미래가 없다면 -1)

// info: 어피치가 맞춘 개수(10점 -> 0점 순)
// - n의 개수가 굉장히 작다(10개 이하)
// 11 ^ 10 / 10!

const int SCORE_N = 11;
const int MAX_SCORE = 10;

int maxGap = 0;
void DfsUtil(int n, const vector<int>& info, vector<int>& cur, vector<int>& answer, int idx)
{
    if(n == 0)
    {
        // Calc Score
        int A = 0;
        int B = 0;
        for(int i = 0; i < SCORE_N; i++)
        {
            int score = MAX_SCORE - i;
            if(info[i] + cur[i] == 0)
                continue;
            
            if(info[i] >= cur[i])
                A += score;
            else
                B += score;
        }
        // cout << A << " " << B << '\n';
        
        int gap = B - A;
        if(gap == maxGap)
        {
           for(int i = SCORE_N-1; i >= 0; i--)
           {
                if(answer[i] != cur[i])
                {
                    if(answer[i] < cur[i])
                        answer = cur;
                    break;
                }
           }
        }
        else if(gap > maxGap)
        {
            maxGap = gap;
            answer = cur;
        }
        
        return;
    }
    
    // DFS Loop
    for(int i = idx; i <= MAX_SCORE; i++)
    {
        if(cur[i] <= info[i])
        {
            cur[i]++;
            DfsUtil(n-1, info, cur, answer, i);
            cur[i]--;
        }
        
    }
}

void Dfs(int n, const vector<int>& info, vector<int>& answer)
{
    if(n == 1)
        return;
    
    vector<int> cur(SCORE_N, 0);
    DfsUtil(n, info, cur, answer, 0);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(SCORE_N, 0);
    Dfs(n, info, answer);
    
    if(maxGap == 0)
    {
        answer = {-1};
    }
    
    // cout << "maxGap: " << maxGap << '\n';
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator() (const vector<int>& p1, const vector<int>& p2) const {
        if(p1[0] == p2[0])
            return p1[1] < p2[1];
        return p1[0] > p2[0];
    }
};

int solution(vector<vector<int>> scores) {
    vector<int> wanho = scores[0];
    
    sort(scores.begin(), scores.end(), cmp());
    
    int maxFirst = scores[0][0];
    int maxSecond = 0;
    vector<vector<int>> incentiveList;
    for(int i = 0; i < scores.size(); i++){
        // 통과가 되는 경우의 수
        // 1) maxFirst가 같음 -> 통과
        // 2) maxFirst가 다름 -> maxSecond를 이겨야함
        // 3) [5, 1] -> [4, 5] -> [4, 3] 문제: 같은 first가 maxSecond가 되어 이전 maxSecond가 가려져서 탈락하는 문제
        // 4) [7, 5] -> [6, 6] -> [6, 4] 문제: 같은 first가 maxSecond가 되어 이전 maxSecond가 가려져서 통과되는 문제
        // => 결국 second에 대해선 오름차순 정렬 필요(같은 first에 가려지는 문제 해결)
        // 확장 일반화 고려: n개의 점수가 있었다면?
        if(scores[i][0] == maxFirst || scores[i][1] >= maxSecond){
            incentiveList.push_back(scores[i]);
            maxSecond = max(maxSecond, scores[i][1]);
            // cout << scores[i][0] << " " << scores[i][1] << '\n';
        }
    }
       
    int answer = 0;
    int wanho_score = wanho[0] + wanho[1];
    if(find(incentiveList.begin(), incentiveList.end(), wanho) == incentiveList.end()){
        answer = -1;
    }
    else{
        answer = count_if(incentiveList.begin(), incentiveList.end(), [wanho_score](const vector<int>& p1){
            int total_score = p1[0] + p1[1];
            return wanho_score < total_score;
        }) + 1;
    }
        
    
    return answer;
}
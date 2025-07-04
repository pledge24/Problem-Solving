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
#include <bits/stdc++.h>

using namespace std;

void split(string& str, string delimeter, pair<string, string>& p1){
    vector<string> ret;
    int idx = 0;
    while(idx < str.size()){
        int nextIdx = str.find(delimeter, idx);
        if(nextIdx == string::npos) nextIdx = str.size();

        if(nextIdx - idx > 0)
            ret.push_back(str.substr(idx, nextIdx-idx));
            
        idx = nextIdx + delimeter.size();
    }

    p1 = make_pair(ret[0], ret[1]);
}

// 1) 지난 달에 두 사람 사이에 "더 많은 선물을 준 사람"이 "선물 1개"를 받는다.
// 2) 지난 달에 선물을 주고받지 않았다면, 총 선물 횟수가 높은 사람이 "선물 1개"를 받는다.
// 3) 총 선물 횟수도 같다면 아무것도 하지 않는다.
// Q. 다음달에 가장 많은 선물을 받은 사람의 "선물 수"는?
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string, int> giftScore; // 선물 지수
    map<string, map<string, int>> giftList; // A가 선물준 친구 리스트.
    
    for(string& elem : gifts){
        pair<string, string> p1; // first: 준 사람, second: 받은 사람
        split(elem, " ", p1);
        
        giftScore[p1.first]++;
        giftScore[p1.second]--;
        
        giftList[p1.first][p1.second]++;
    }
    
    // for(auto elem : giftScore){
    //     cout << elem.first << " " << elem.second << '\n';    
    // }
    
    // for(int i = 0; i < friends.size(); i++){
    //     string nameA = friends[i];
    //     cout << nameA << " ";
    //     for(int j = 0; j < friends.size(); j++){
    //         string nameB = friends[j];
    //         cout << giftList[nameA][nameB] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    map<string, int> finalScore; // 선물 지수
    
    int maxScore = 0;
    for(int i = 0; i < friends.size(); i++){
        string nameA = friends[i];

        for(int j = 0; j < friends.size(); j++){
            string nameB = friends[j];
            
            int scoreA = giftList[nameA][nameB];
            int scoreB = giftList[nameB][nameA];
            
            if(scoreA > scoreB)
                finalScore[nameA]++;
            else if((scoreA == scoreB) && (giftScore[nameA] > giftScore[nameB]))
                finalScore[nameA]++;
        }

        maxScore = max(maxScore, finalScore[nameA]);
        // cout << "maxScore: " << nameA << " " << maxScore << '\n';
    }
    
    answer = maxScore;
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m1;
    
    for(int i = 0; i < name.size(); i++){
        m1[name[i]] = yearning[i];
    }
    
    for(int i = 0; i < photo.size(); i++){
        int score = 0;  
        for(auto elem : photo[i]){
            score += m1[elem];
        }
        answer.push_back(score);
    }
    
    return answer;
}
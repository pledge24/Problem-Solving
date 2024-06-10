#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> pattern1 = {1, 2, 3, 4, 5};
    vector<int> pattern2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> pattern3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> score_list(3);
    int size_p1 = pattern1.size(), size_p2 = pattern2.size(), size_p3 = pattern3.size();
    int idx_p1 = 0, idx_p2 = 0, idx_p3 = 0;
    for(int elem : answers){
        score_list[0] += (pattern1[idx_p1] == elem);
        score_list[1] += (pattern2[idx_p2] == elem);
        score_list[2] += (pattern3[idx_p3] == elem);
        
        idx_p1 = (idx_p1 + 1) % size_p1;
        idx_p2 = (idx_p2 + 1) % size_p2;
        idx_p3 = (idx_p3 + 1) % size_p3;
    }
    
    int max_score = *max_element(score_list.begin(), score_list.end());
    
    for(int i = 0; i < 3; i++){
        if(max_score == score_list[i]){
            answer.push_back(i+1);
        }
    }
    return answer;
}
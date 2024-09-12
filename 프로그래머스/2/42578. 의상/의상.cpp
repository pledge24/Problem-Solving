#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m1;
    int answer = 0;
    
    string category;
    for(int i = 0; i < clothes.size(); i++){
        category = clothes[i][1];
        m1[category]++;
    }
    int m1_size = m1.size();
    
    vector<int> v1;
    int idx = 1;
    for(auto it : m1){
       v1.push_back(it.second);
    }
    
    vector<int> case1(m1_size);     // 해당 카테고리의 옷을 선택한 경우.
    vector<int> case2(m1_size);     // 해당 카테고리의 옷을 선택하지 않은 경우.
        
    case1[0] = v1[0];
    case2[0] = 1;
    for(int i = 1; i < m1_size; i++){
        case1[i] = case1[i-1] * v1[i] + case2[i-1] * v1[i];
        case2[i] = case2[i-1] + case1[i-1];
    }
    
    // 하나도 착용하지 않는 경우는 포함하지 않으므로 1을 뺀다.
    answer = case1[m1_size-1] + case2[m1_size-1] - 1;
    return answer;
}
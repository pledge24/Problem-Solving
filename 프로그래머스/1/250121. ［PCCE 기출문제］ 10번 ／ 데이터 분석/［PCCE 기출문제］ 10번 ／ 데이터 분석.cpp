#include <bits/stdc++.h>

using namespace std;

// data에서 ext 값이 val_ext보다 작은 데이터를 뽑는다.
// sort_by에 해당하는 값을 오름차순으로 정렬한다.
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    map<string, int> m1 = {make_pair("code", 0), make_pair("date", 1), make_pair("maximum", 2), make_pair("remain", 3)};
    
    int idx = m1[ext];
    for(auto elem : data){
        if(elem[idx] < val_ext)
            answer.push_back(elem);
    }
    
    int sort_type = m1[sort_by];
    sort(answer.begin(), answer.end(), [sort_type](vector<int> v1, vector<int> v2){
        return v1[sort_type] < v2[sort_type];
    });
        
    return answer;
}
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct pos_data{
    int num;
    int idx;
};

// 내림차순 정렬
bool operator<(const pos_data& a, const pos_data& b){
    return a.num > b.num;
} 

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    answer.resize(numbers.size(), -1);
    
    priority_queue<pos_data> pq;
    
    pq.push({numbers[0], 0});
    for(int i = 1; i < numbers.size(); i++){
        while(!pq.empty() && pq.top().num < numbers[i]){
            answer[pq.top().idx] = numbers[i];
            pq.pop();
        }
        pq.push({numbers[i], i});
    }
    return answer;
}
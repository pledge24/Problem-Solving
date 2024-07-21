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
    
    // O(NlogN)...?
    pq.push({numbers[0], 0});
    for(int i = 1; i < numbers.size(); i++){
        // 다음 수가 pq에 저장된 가장 큰 num보다 크다면 
        // 다음 수를 해당 숫자의 뒷 큰수로 취급한다.(숫자가 있었던 자리는 idx)
        // pq에 저장된 수가 다음 수보다 큰 수가 없을 때까지 반복한다. 
        while(!pq.empty() && pq.top().num < numbers[i]){
            answer[pq.top().idx] = numbers[i];
            pq.pop();
        }
        pq.push({numbers[i], i});
    }
    return answer;
}
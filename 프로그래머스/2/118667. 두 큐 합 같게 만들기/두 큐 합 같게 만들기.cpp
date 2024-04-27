#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct pos_data{
    int start;
    int end;
};

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = INT_MAX;
    long long q_sum1 = 0, q_sum2 = 0;
    
    vector<int> merge_q;
    
    for(int elem1 : queue1){
        q_sum1 += elem1;
        merge_q.push_back(elem1);
    } 
    for(int elem2 : queue2){
        q_sum2 += elem2;
        merge_q.push_back(elem2);
    } 
    
    int start = 0, end = 0;
    long long sum = merge_q[0], sum_tgt = (q_sum1 + q_sum2) / 2;
    
    // 두 큐의 합이 홀수이면 -1.
    if((q_sum1 + q_sum2) % 2) return -1;
    
    vector<pos_data> pos_v1;
    do{
        
        if(sum < sum_tgt){
            end++;
            sum += merge_q[end];
        }
        else if(sum >= sum_tgt){    
            if(sum == sum_tgt){
                pos_v1.push_back({start, end});
            }
            
            sum -= merge_q[start];
            start++;
        }
        
    }
    while(start <= end && end < merge_q.size());
    
    // 큐의 합을 같게 만들 수 있는 경우를 찾지 못한 경우 -1
    if(pos_v1.size() == 0) return -1;
    
    for(pos_data pd : pos_v1){
        //cout << pd.start << " " << pd.end << '\n';
    
        int pop_cnt = pd.start;
        int push_cnt = pd.end < queue1.size() ? 0 : pd.end + 1 - queue1.size();
        
        if(pd.end < queue1.size() - 1){
            pop_cnt = pd.end + 1;
            push_cnt = queue2.size();
        }
        
        //cout << pop_cnt << " " << push_cnt << '\n'; 

        answer = min(answer, pop_cnt + push_cnt);
    
    }
    
    return answer;
}
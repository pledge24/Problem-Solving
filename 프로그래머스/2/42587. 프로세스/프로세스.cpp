#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct pos_data{
    int idx;
    int p;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    deque<pos_data> dq;
    
    for(int i = 0; i < priorities.size(); i++){
        dq.push_back({i, priorities[i]});
    }
    
    int cnt = 0;
    bool find = false;
    while(!find){
        pos_data cur_proc = dq.front(); dq.pop_front();
        
        int max_p = -1;
        for(pos_data pd : dq){
            max_p = max(max_p, pd.p);
        }
        
        if(cur_proc.p < max_p){
            dq.push_back(cur_proc);
        }
        else{
            cnt++;
            if(cur_proc.idx == location) find = true;
        }
        
        if(find) break;
    }
    
    answer = cnt;
    
    return answer;
}
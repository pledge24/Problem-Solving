#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
      
    queue<int> q;

    for(int elem : numbers){
           
        // q가 비어있을 때 (처음 들어올 때) 진입.
        if(q.empty()){
            q.push(elem);
            q.push(-elem);
            continue;
        }
        
        int q_size = q.size();
        
        for(int i = 0; i < q_size; i++){
            
            int cur_x = q.front(); q.pop();
                 
            q.push(cur_x + elem);
            q.push(cur_x - elem);
        }

    }

    while(!q.empty()){
        int cur_x = q.front(); q.pop();
        if(cur_x == target) answer++;
    }
    return answer;
}
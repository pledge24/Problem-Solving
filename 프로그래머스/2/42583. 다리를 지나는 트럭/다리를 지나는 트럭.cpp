#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int cur_time = 0;
    int cur_w = 0;
    queue<int> q;
    
    for(int truck_w : truck_weights){
        
        // 맨 처음 시작시 트럭을 push한다.
        if(q.empty()){
            q.push(truck_w);
            cur_w += truck_w;
            
            cur_time++;
            cout << cur_w << '\n';
            
            continue;
        } 
        
        bool find = false;
        
        while(!find){
            cur_time++;
            
            // q에 들어가 있는 원소의 개수가 다리의 길이보다 작을 때.
            if(q.size() < bridge_length){
                
                if(cur_w + truck_w > weight){
                    q.push(0);
                }
                else{
                    q.push(truck_w);
                    cur_w += truck_w;
                    find = true;
                }
            }
            // q에 들어가 있는 원소의 개수가 다리의 길이와 같을 때.
            else{
                if(cur_w - q.front() + truck_w > weight){
                    q.push(0);
                }
                else{
                    q.push(truck_w);
                    cur_w += truck_w;
                    find = true;
                }
                
                cur_w -= q.front(); q.pop();
            }
        
            
            
        }
              
    }
    
    // 마지막 트럭은 push만 되고 이동하지 않았으니, 마지막 트럭이 다리를 지나는 시간(bridge_length)을 추가한다.
    answer = cur_time + bridge_length;
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct stack_data{
    int ingre;
    int step;
};

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<stack_data> s;
    
    for(int elem : ingredient){
        // 스택이 비어있는 경우.
        if(s.empty()){
            if(elem == 1) s.push({elem, 1});
            else s.push({elem, 0});                     
            continue;
        }
                
        stack_data prev = s.top();
        
        // 이전에 연결된 상황이고, 현재 재료와 연결될 경우
        if(prev.step > 0 && (prev.ingre % 3 + 1) == elem){ 
            if(elem == 1){
                s.pop(); s.pop(); s.pop();
                answer++;
            }
            else{
                s.push({elem, prev.step+1});    
            }
                   
        }
        else{
            if(elem == 1) s.push({elem, 1});
            else s.push({elem, 0});
        }
    }
    
    cout << 3 % 3 + 1 << '\n';
    return answer;
}
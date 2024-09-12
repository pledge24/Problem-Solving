#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    
    int cur_box = 1;
    
    bool find;
    for(int o : order){
       
        find = false;
        // 만약 현재 박스 번호보다 주문 번호가 높다면,
        if(cur_box < o){
            //cout << "따로 저장\n";
            while(cur_box < o){
                s.push(cur_box);
                cur_box++;
            }
            find = true;
            answer++;
            
            cur_box++;
        }
        else if(cur_box > o){
            //cout << "작은 컨베이어벨트\n";
            int box_no = s.top(); s.pop();
            if(box_no == o){
                find = true;
                answer++;
            }
            
        }
        else{
            //cout << "바로찾음\n";
            find = true;
            answer++;
            cur_box++;
        }
        
        if(!find) break;
        
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int idx = 1;
    char first = s[0];
    int cnt_first = 1;
    int cnt_others = 0;
    bool isSplit = false;
    while(idx < s.length()){
        isSplit = false;
        // 개수 카운터.
        if(first == s[idx]) {cnt_first++;}
        else{cnt_others++;}        
        
        // 같으면 정답 수 올리고, 해당 위치에서 모든 변수 초기화.
        if(cnt_first == cnt_others){
            isSplit = true;
            cnt_first = 0;
            cnt_others = 0;
            answer++;
        }

        idx++;
        
        if(isSplit){
            first = s[idx];
        }
    }
   
    // 분리가 되지 않고 나왔을 시 하나 추가.
    if(!isSplit){
        answer++;
    }
    return answer;
}
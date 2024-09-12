#include <bits/stdc++.h>

#define MAXLEN 1'000'001

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int ans_s = -1, ans_e = MAXLEN;
    int start = 0, end = 0;
    int sum = sequence[0];
    
    do{
        // 부분 수열의 합이 작았다면, end를 1칸 이동시키고 end 위치의 원소 값을 sum에 더한다.
        if(sum < k){
            end++;
            sum += sequence[end];                
        }
        // 부분 수열의 합이 작지 않았다면, start를 1칸 이동시키고 start 위치의 원소 값을 sum에서 뺀다.
        // 만약 부분 수열의 합이 같았다면, 해당 start와 end값을 부분 수열의 길이가 작았을 때 정답으로 저장한다.
        else{
            if(sum == k && (end - start < ans_e - ans_s)){
                ans_s = start;
                ans_e = end;
               
            }
            sum -= sequence[start];   
            start++;
        }
        
    }
    while(start <= end && end < sequence.size());
        
    answer = {ans_s, ans_e};
    
    return answer;
}
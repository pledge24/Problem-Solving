#include <bits/stdc++.h>

#define MAXLEN 1'000'001

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int ans_s = -1, ans_e = MAXLEN;
    int start = 0, end = 0;
    int sum = sequence[0];
    int cnt = 0;
    do{
        if(sum < k){
            end++;
            sum += sequence[end];          
            //cout << "cnt1 : " << cnt << " " << sum << '\n';
        }
        else{
            if(sum == k && (end - start < ans_e - ans_s)){
                ans_s = start;
                ans_e = end;
                //cout << "check\n";
            }
            sum -= sequence[start];   
            start++;
            //cout << "cnt2 : " << cnt << " " << sum << '\n';
        }
        
        cnt++;
    }
    while(start <= end && max(start, end) < sequence.size());
        
    answer = {ans_s, ans_e};
    
    return answer;
}
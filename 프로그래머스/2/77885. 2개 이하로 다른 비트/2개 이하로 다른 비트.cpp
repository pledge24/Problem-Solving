#include <bits/stdc++.h>
#include <cmath>

#define MAXLEN 64

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long elem : numbers){
        
        // 예외 처리: 값이 0이면 정답은 1이다. (모든 비트가 0인 경우 제외).
        if(elem == 0){
            answer.push_back(1);
            continue;
        }
        
        vector<int> v1(MAXLEN);
        long long temp_elem = elem;
        for(int idx = 0; temp_elem > 0; idx++){
            v1[idx] = temp_elem % 2;
            temp_elem /= 2;
        }
               
        // 0, 1의 위치를 벡터에 저장.
        vector<int> one_v;
        vector<int> zero_v;
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] > 0){
                one_v.push_back(i);
            } 
            else {    
                zero_v.push_back(i);
            }           
        }


        // 0 -> 1
        long long a = 1;
        a = a << zero_v[0];      
        
        long long b = 1;
        for(int i = 1; i < v1.size(); i++){
            if(v1[i] == 0 && v1[i-1] == 1){           
                b = (b << (i-1));
                break;
            }
        }
        
        answer.push_back(elem + min(a, b));
        
        
    }
    return answer;
}
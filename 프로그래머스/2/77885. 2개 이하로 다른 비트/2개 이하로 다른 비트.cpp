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
               
       
        // 0 -> 1
        long long a = 1;
        for(int i = 0; i < v1.size(); i++){
            // 가장 작은 0을 찾고 해당 위치를 1로 바꾼 것이 답.
            if(v1[i] == 0){
                a = a << i;   
                break;
            }
        }
        
        // 01 -> 10
        long long b = 1;
        for(int i = 1; i < v1.size(); i++){
            // 가장 작은 01 패턴을 찾고 해당 1의 값이 답.
            if(v1[i] == 0 && v1[i-1] == 1){  
                // 숫자는 기본 int형이다. 1을 << 하게되면 int형이라 오버플로우가 발생할 수 있다.
                b = (b << (i-1));
                break;
            }
        }
        
        answer.push_back(elem + min(a, b));
    
    }
    return answer;
}
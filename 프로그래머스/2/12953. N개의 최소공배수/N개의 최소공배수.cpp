#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> arr) {
    long long answer = 1;
    
    map<int, int> total_m;
    
    for(int elem : arr){
        map<int, int> m;
        for(int n = 2; n <= elem;){
            if(elem % n == 0){
                elem /= n;
                m[n]++;
            }
            else{
                n++;
            }
        }
        
        for(auto it : m){
            //cout << it.first << " " << it.second << '\n';
            total_m[it.first] = max(total_m[it.first], it.second);
        }
    }
    
    // 최소 공배수 구해서 정답에 넣기
    for(auto it : total_m){       
        for(int i = 0; i < it.second; i++){
            answer *= it.first;
        }
    }
    
    return answer;
}
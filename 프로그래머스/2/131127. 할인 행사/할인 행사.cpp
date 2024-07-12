#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    
    for(int i = 0; i < discount.size(); i++){
        if(i < 9){
            m[discount[i]]++;
            continue;
        }
        
        m[discount[i]]++;
        bool find = true;
        for(int n = 0; n < want.size(); n++){
            if(m[want[n]] != number[n]){
                find = false;
                break;
            } 
        }
        
        if(find){
            answer++;
            cout << i << '\n';
        } 
        m[discount[i-9]]--;
    }
    return answer;
}
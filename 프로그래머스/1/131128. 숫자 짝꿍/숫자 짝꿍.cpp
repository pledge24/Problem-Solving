#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    vector<int> v1(10);
    vector<int> v2(10);
    
    for(char c : X){
        v1[c - '0'] ++;
    }
    
    for(char c : Y){
        v2[c - '0'] ++;
    }
    
    for(int i = 9; i >= 0; i--){
        int cnt = min(v1[i], v2[i]);
        
        if(i == 0 && answer.length() == 0){
            answer.append(min(cnt, 1), '0');
            break;
        }
        
        answer.append(cnt, '0' + i);
    }
    
    answer = answer == "" ? "-1" : answer;
    
    return answer;
}
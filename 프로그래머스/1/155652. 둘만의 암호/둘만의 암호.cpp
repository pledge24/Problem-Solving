#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(char c : s){
        int cnt = index;
        while(cnt > 0){
            
            c = c+1 > 'z' ? 'a': c+1; 
            
            if(skip.find(c) == string::npos){ // skip에 포함되지 않은 경우
               cnt--;  
            }
            
            
        }
        answer += c;
    }
    return answer;
}
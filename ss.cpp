"#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for(int i = 0; i <= t.length() - p.length(); i++){
        
        if(t.substr(i, p.length()) <= p ) answer++;
        
    }
    return answer;
}"

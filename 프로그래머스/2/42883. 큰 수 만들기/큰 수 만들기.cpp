#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int n = 0;
    bool find;
    
    for(int i = 0; i < k; i++){
        find = false;
        for(int j = 0; j < number.length() - 1; j++){
            if(number[j] < number[j+1]){
                number.erase(j, 1);
                find = true;
                break;
            }
            
        }
        
        if(!find){
            int idx = min_element(number.begin(), number.end()) - number.begin();
            number.erase(idx, 1);
        }
    }
    
    answer = number;
    
    return answer;
}
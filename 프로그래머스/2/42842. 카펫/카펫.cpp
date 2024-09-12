#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    bool find = false;
    
    int height = 3, width = 3;
    int cur_brown, cur_yellow;
    while(!find){
        
        for(int h = 3; h <= width; h++){
            cur_brown = width*2 + h*2 - 4;
            cur_yellow = (width-2) * (h-2);
            
            if(cur_brown == brown && cur_yellow == yellow){
                height = h;
                answer = {width, height};
                find = true;
                break;
            }
        }
        if(find) break;
        
        width++;
    }
    
    
    
    return answer;
}
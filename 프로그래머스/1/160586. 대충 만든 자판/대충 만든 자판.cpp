#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<map<char, int>> v1(keymap.size());
    
    for(int i = 0; i < keymap.size(); i++){   
        for(int j = 0; j < keymap[i].length(); j++){
            char c = keymap[i][j];
            if(v1[i][c] == 0){       
                v1[i][c] = j+1;
            }
        }
    }
    
    for(int i = 0; i < targets.size(); i++){
        int sum = 0;
        for(char c : targets[i]){
            int temp_n = 101;
            for(int j = 0; j < v1.size(); j++){
                if(v1[j][c] == 0) continue;
                temp_n = min(temp_n, v1[j][c]);
            }
            
            if(temp_n == 101){
                sum = -1;
                break;
            }
            else{
                sum += temp_n;
            }
            
        }
        answer.push_back(sum);
    }
    return answer;
}
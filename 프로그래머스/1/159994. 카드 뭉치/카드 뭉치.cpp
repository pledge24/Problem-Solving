#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    bool possible = true;
    int idx1 = 0, idx2 = 0, idx_goal = 0;
   
    for(string s : goal){
        if(idx1 < cards1.size() && cards1[idx1] == s){
            idx1++;
        }
        else if(idx2 < cards2.size() && cards2[idx2] == s){
            idx2++;
        }
        else{
            possible = false;
            break;
        }
    }
           
    answer = possible ? "Yes" : "No";
    
    return answer;
}
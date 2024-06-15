#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> babu_list = { "aya", "ye", "woo", "ma"};
    
    for(int i = 0; i < babbling.size(); i++){
        for(int j = 0; j < babu_list.size(); j++){
            while(babbling[i].find(babu_list[j]) != string::npos){
                babbling[i].replace(babbling[i].find(babu_list[j]), babu_list[j].length(), to_string(j)); 
            }
                 
        }
    }
    
    bool ispossible;
    char prev_c;
    for(string s : babbling){
        cout << s << ' ';
        ispossible = true;
        prev_c = '9';
        for(char c : s){
            if(!isdigit(c) || prev_c == c){
                ispossible = false;
                break;
            } 
            
            prev_c = c;
        }
        
        answer += (ispossible);
    }
    
    return answer;
}
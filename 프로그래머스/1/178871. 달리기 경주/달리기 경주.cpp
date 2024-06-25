#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> m;
    
    for(int i = 0; i < players.size(); i++){
        m[players[i]] = i;
    }
    string s_temp;
    for(string s : callings){
        int idx = m[s];
        s_temp = players[idx-1];
        players[idx-1] = players[idx];
        players[idx] = s_temp;
        
        m[players[idx]] = idx;
        m[players[idx-1]] = idx-1;
    }
    
    answer = players;
    return answer;
}
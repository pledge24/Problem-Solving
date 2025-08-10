#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> m1;
    for(auto elem : participant){
        m1[elem]++;
    }
    
    for(auto elem : completion){
        m1[elem]--;
    }
    
    for(auto elem : m1){
        if(elem.second > 0)
            answer = elem.first;
    }
    
    return answer;
}
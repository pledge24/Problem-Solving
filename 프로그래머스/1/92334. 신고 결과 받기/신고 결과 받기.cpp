#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, map<string, bool>> m;   // report변수 2차원 배열로 재구성
    map<string, int> m_cnt;             // 각 사용자의 신고 받은 건수
    
    // 모든 신고 데이터를 저장
    string sender, receiver;
    for(string s : report){
        stringstream ss(s);
        ss >> sender;
        ss >> receiver;
        
        if(!m[sender][receiver]){
            m[sender][receiver] = true; 
            m_cnt[receiver]++;
        }
         
    }
    
    for(string s : id_list){
        int ban_cnt = 0;
        for(auto it : m[s]){
            if(m_cnt[it.first] >= k){
                ban_cnt++;
            } 
        }
        answer.push_back(ban_cnt);
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

struct fee_log{
    int intime = -1;
    int use_time = 0; 
};

struct fee_data{
    int basic_t;
    int basic_fee;
    int unit_time;
    int unit_fee;
};

fee_data f;

int getFee(int gap_time){
    int fee;
    
      
    if(gap_time - f.basic_t > 0){
        int add_time = gap_time - f.basic_t;
        
        fee = f.basic_fee + ceil((double)add_time / f.unit_time) * f.unit_fee;
        
    }
    else{
        fee = f.basic_fee;
    }
    
    //cout << "Fee: " << fee << '\n';
    
    return fee;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, fee_log> m;
    f = {fees[0], fees[1], fees[2], fees[3]};
    
    vector<fee_log> log;
    
    for(string s : records){
        stringstream ss(s);
        
        string cur_time, cur_name, cur_inout;
        
        ss >> cur_time;
        ss >> cur_name;
        ss >> cur_inout;
        
        stringstream hhmm(cur_time);
        
        string hh, mm;
        getline(hhmm, hh, ':');
        getline(hhmm, mm, ':');
        
        int time_n = stoi(hh) * 60 + stoi(mm) + 1;
        if(cur_inout == "IN"){
            m[cur_name].intime = time_n;
        } 
        else{
            m[cur_name].use_time += time_n - m[cur_name].intime;
            m[cur_name].intime = -1;
        }
        
        //cout << cur_time << cur_name << cur_inout << '\n';
    }
    
    for(auto it : m){
        if(it.second.intime != -1){
            it.second.use_time += 24*60 - it.second.intime;
            it.second.intime = -1;
        }
        //cout << it.first << " " << it.second.use_time << " " << it.second.intime << '\n';
        
        answer.push_back(getFee(it.second.use_time));
    }
    
    return answer;
}
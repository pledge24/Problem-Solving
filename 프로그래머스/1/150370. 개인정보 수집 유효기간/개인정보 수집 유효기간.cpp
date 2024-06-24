#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<string> today_num;

vector<string> getDate(string str){
    
    vector<string> temp_s(3);
    
    stringstream ss(str);
    
    getline(ss, temp_s[0], '.');
    getline(ss, temp_s[1], '.');
    getline(ss, temp_s[2], '.');
        
    return temp_s;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> m;
    
    today_num = getDate(today);
    
    // for(string s : today_num){
    //     cout << s << '\n';
    // }
    
    string type_name, type_period;
    for(string s: terms){
        stringstream ss(s);
        ss >> type_name;
        ss >> type_period;
        
        m[type_name[0]] = stoi(type_period);
        //cout << type_name << " " << type_period << '\n';
    }
    
    string date_temp, type_temp;
    for(int i = 0; i < privacies.size(); i++){
        stringstream temp_ss(privacies[i]);
                
        temp_ss >> date_temp;
        temp_ss >> type_temp;
        
        vector<string> privacy_temp = getDate(date_temp);
        
        int cur_months = (stoi(privacy_temp[1]) + m[type_temp[0]]);  
        //cout << cur_months << '\n';
        privacy_temp[1] = to_string((cur_months-1) % 12 + 1);
        if(privacy_temp[1].size() == 1) privacy_temp[1] = "0" + privacy_temp[1];
        int carry = (cur_months-1) / 12;
        privacy_temp[0] = to_string(stoi(privacy_temp[0]) + carry);
        
        // for(string s : privacy_temp){
        //     cout << s << '\n';
        // }
        
        string s1 = today_num[0] + today_num[1] + today_num[2];
        string s2 = privacy_temp[0] + privacy_temp[1] + privacy_temp[2];
        //cout << s1 << " "<< s2 << '\n';
        if(s1 >= s2){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}
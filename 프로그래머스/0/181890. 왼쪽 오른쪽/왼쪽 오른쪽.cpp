#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    
    int l_pos = std::find(str_list.begin(), str_list.end(), "l") - str_list.begin();
    int r_pos = std::find(str_list.begin(), str_list.end(), "r") - str_list.begin();
    
    cout << l_pos << " " << r_pos << '\n';
    
    if(l_pos == str_list.size() && r_pos == str_list.size())
    {
    
    }
    else if(l_pos < r_pos)
    {
        std::copy(str_list.begin(), str_list.begin()+l_pos, back_inserter(answer));
    }
    else if(l_pos > r_pos)
    {
        std::copy(str_list.begin()+r_pos+1, str_list.end(), back_inserter(answer));
    }
    
    return answer;
}
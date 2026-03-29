#include <bits/stdc++.h>

using namespace std;

string solution(string n_str) {
    string answer = "";
    
    int s = n_str.find_first_not_of("0");
    answer = n_str.substr(s);
    
    return answer;
}
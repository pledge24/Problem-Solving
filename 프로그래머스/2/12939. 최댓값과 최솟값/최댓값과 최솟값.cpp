#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    string str;
    
    vector<int> v1;
    while(ss >> str){
        v1.push_back(stoi(str));
    }
    
    int min_num = *min_element(v1.begin(), v1.end());
    int max_num = *max_element(v1.begin(), v1.end());
    
    answer = to_string(min_num) + " " + to_string(max_num);
    return answer;
}
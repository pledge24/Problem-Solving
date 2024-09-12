#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt_zero = 0, cnt, num;
    int loop = 0;
    while(s != "1"){
        cnt = 0;   
        for(char c : s){
            if(c == '0'){
                cnt++;
            }
        }
        num = s.length() - cnt;
        cnt_zero += cnt;
        
        s = "";
        while(num > 0){
            s += (num % 2) + '0';
            num /= 2;
        }
        reverse(s.begin(), s.end());
        cout << s << '\n';
        loop++;
    }
    
    answer = {loop, cnt_zero};
    return answer;
}
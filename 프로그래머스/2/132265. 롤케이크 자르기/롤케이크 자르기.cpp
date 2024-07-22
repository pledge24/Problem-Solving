#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int, int> m1;
    map<int, int> m2;
    
    for(int elem : topping){
        m2[elem]++;
    }
    
    int idx =0;
    for(int elem : topping){
        m1[elem]++;
        m2[elem]--;
        if(m2[elem] == 0) m2.erase(elem);
        
        if(m1.size() == m2.size()) answer++;
        //cout << idx << " " << m1.size() << " " << m2.size() << '\n';
        idx++;
    }
    return answer;
}
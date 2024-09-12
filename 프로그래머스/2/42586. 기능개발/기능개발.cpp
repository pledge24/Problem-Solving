#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> v1(speeds.size());
    for(int i = 0; i < speeds.size(); i++){
        int days = ceil((100.0 - progresses[i]) / speeds[i]);
        if(i == 0){
            v1[i] = days;
            cout << days << ' ';
            continue;
        }
        
        v1[i] = max(days, v1[i-1]);
        cout << v1[i] << ' ';
    }
    
    int cnt = 1;
    int num = v1[0];
    for(int i = 1; i < v1.size(); i++){
        if(num != v1[i]){
            answer.push_back(cnt);
            cnt = 1;
            num = v1[i];
        }
        else{
            cnt++;
        }
               
    }
    
    answer.push_back(cnt);
    
    return answer;
}
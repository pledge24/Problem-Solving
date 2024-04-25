#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

int getTime(string s){
    stringstream ss(s);
        
    string hh, mm;
    getline(ss, hh, ':');
    getline(ss, mm, ':');

    //cout << hh << " " << mm << '\n';
    
    return stoi(hh)*60 + stoi(mm);
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<vector<int>> meetingTimings;
    for(vector<string> s_list : book_time){
        int start_t = getTime(s_list[0]);
        int end_t = getTime(s_list[1]) + 10;
        
        //cout << start_t << " " << end_t << '\n';
        
        meetingTimings.push_back({start_t, end_t});
    }
    
    sort(meetingTimings.begin(), meetingTimings.end(), [](vector<int>&a, vector<int>&b){
       return a[0] < b[0]; 
    });
         
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(meetingTimings[0][1]);
    
    for(int i = 1; i < meetingTimings.size(); i++){
        if(meetingTimings[i][0] >= minHeap.top()){
            minHeap.pop();
        }
        
        minHeap.push(meetingTimings[i][1]);
    }
    
    answer = minHeap.size();
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;

// 1) 10초 전으로 이동, 2) 10초 후로 이동, 3) 오프닝 건너뛰기
// 1) -> prev 명령 입력 시, 최소 0초로 이동
// 2) -> next 명령 입력 시, 최대 마지막 위치로 이동
// 3) -> 오프닝 구간에 있는 경우, 오프닝이 끝나는 위치로 이동

int videoLen;
int opStart;
int opEnd;

void split(const string str, vector<string>& splitted, string delimiter){
    int idx = 0;
    while(idx < str.length()){
        int nextIdx = str.find(delimiter, idx);
        
        if(nextIdx == string::npos)
            nextIdx = str.size();
        
        int len = nextIdx - idx;
        if(len > 0)
            splitted.push_back(str.substr(idx, len));

        idx = nextIdx + 1;
    }
    
    return;
}

int timeToNum(const string time){
    vector<string> mmss;
    split(time, mmss, ":");
    
    int mm = stoi(mmss[0]);
    int ss = stoi(mmss[1]);
    
    return mm*60 + ss;
}

void applyCmd(int& curTime, string& cmd){
    if(cmd == "prev"){
        curTime = max(0, curTime - 10);
        if(opStart <= curTime && curTime <= opEnd){
            curTime = opEnd;
        }
    }
    else if(cmd == "next"){
        curTime = min(videoLen, curTime + 10);
        if(opStart <= curTime && curTime <= opEnd){
            curTime = opEnd;
        }
    }
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    videoLen = timeToNum(video_len);
    opStart = timeToNum(op_start);
    opEnd = timeToNum(op_end);
    
    cout << videoLen << " " << opStart << " " << opEnd << '\n';
    
    int curTime = timeToNum(pos);
    if(opStart <= curTime && curTime <= opEnd){
        curTime = opEnd;
    }
    
    for(auto cmd : commands){
        applyCmd(curTime, cmd);
    }
    
    int width = 2;
    
    string mm = to_string(curTime / 60);   
    if(mm.length() < 2)
        mm.insert(0, 1, '0');
    
    string ss = to_string(curTime % 60);
    if(ss.length() < 2)
            ss.insert(0, 1, '0');
    
    cout << mm << " " << ss << '\n';
    
    answer = mm + ":" + ss;
    
    return answer;
}
#include <bits/stdc++.h>

#define OUT

using namespace std;

// 1. 총 3번. 횟수마다 0~10점 획득 가능
// 2. S, D, T 영역을 Hit시 1~3제곱 획득
// 3. *은 (현재 점수 + 이전 점수) 2배, #은 -해당 점수 ()
// 4. *이 처음에 나오면 현재 점수만 2배. 
// 5. *은 또다른 *이나 #과 연계될 수 있다.
void split(string& dartResult, vector<pair<int, string>>& OUT commands){
    string digits = "0123456789";
    
    size_t start = 0;
    while(start < dartResult.length()){
        string num = "";
        string cmd = "";
        
        // 점수 추출(숫자 추출)
        size_t endNum = dartResult.find_first_not_of(digits, start);
        int numLen = endNum - start;
        num = dartResult.substr(start, numLen);
        
        start = endNum;
        
        // 커맨드 추출
        size_t next = dartResult.find_first_of(digits, start);
        if(next == string::npos)
            next = dartResult.length();
        int cmdLen = next - start;
        cmd = dartResult.substr(start, cmdLen);
        
        start = next;
        
        commands.push_back(make_pair(stoi(num), cmd));
    }
}

int solution(string dartResult) {
    int answer = 0;
    
    vector<pair<int, string>> commands; // <num, cmd>
    split(dartResult, OUT commands);
    
    // DEBUG
    // for(auto elem : commands){
    //     cout << elem.first << " " << elem.second << '\n';
    // }
    
    int total_score = 0;
    map<char, int> expMap = {
        make_pair('S', 1),
        make_pair('D', 2),
        make_pair('T', 3)
    };
    
    vector<int> scores(commands.size());
    for(int i = 0; i < commands.size(); i++){
        int score = commands[i].first;
        const string& cmd = commands[i].second;
        
        // calc expScore
        int expScore = pow(score, expMap[cmd[0]]);
        
        if(cmd.length() >= 2){
            expScore *= cmd[1] == '*' ? 2 : -1;
            if(i != 0)
                scores[i-1] *= cmd[1] == '*' ? 2 : 1;
        }
        
        scores[i] = expScore;
        
    }
    
    for(int elem : scores)
        answer += elem;
    
    return answer;
}
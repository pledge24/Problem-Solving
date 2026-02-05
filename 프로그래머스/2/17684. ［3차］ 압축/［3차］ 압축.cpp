#include <bits/stdc++.h>

using namespace std;

// 무손실 압축 알고리즘(LZW) 사용
// 1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화
// 2. 사전에서 현재 입력과 일치하는 "가장 긴 문자열 w" 찾기
// 3. w의 idx를 출력하고, 입력에서 w 제거
// 4. 입력에서 처리되지 않은 글자 c가 있다면, w+c를 사전에 등록한다.
// 5. 2번으로 회귀

// "영문 대문자"로만 이루어져 있음.
vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m1;
    
    // Init
    int nextIdx = 1;
    for(char c = 'A'; c <= 'Z'; c++)
    {
        m1[{c}] = nextIdx;
        nextIdx++;
    }
    
    // Process
    int pos = 0;
    while(pos < msg.length())
    {
        string temp = {msg[pos]};
        // Step 2
        while(pos + 1 < msg.length() && m1.find(temp + msg[pos+1]) != m1.end())
        {
            temp += msg[pos+1];
            pos++;
        }
        
        // Step 3
        answer.push_back(m1[temp]);
        
        // if Left
        if(pos + 1 < msg.length())
        {
            m1[temp + msg[pos+1]] = nextIdx;
            nextIdx++;
        }
        
        pos++;
    }
    
    return answer;
}
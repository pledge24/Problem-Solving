#include <bits/stdc++.h>

using namespace std;

// 파일명 포맷
// 영문 대소문자, 숫자, 공백, 마침표, 빼기 부호로 구성됨
// 영문자로 시작, 숫자를 하나 이상 포함
// HEAD_NUMBER_TAIL로 구성됨
// Head는 숫자가 아닌 문자로 구성(최소 한 글자)
// Number는 1~5글자의 연속된 숫자, 앞에 0이 올 수 있음
// Tail은 숫자가 올 수도, 아무것도 없을 수도 있음.

// = 파일 정렬 기준 ===ㄱ
// 1. HEAD 기준 사전순 정렬. 대소문자 구분 X
// 2. NUMBER 순자 순으로 정렬. 012와 12는 같은 순위로 처리
// 3. 그 외의 경우 기존 정렬순으로 정렬.
struct FileData
{
    string head = "";
    string number = "";
    string tail = "";
    int idx = 0;
};

string ToLower(const string& s)
{
    string res = "";
    for(char c : s)
    {
        res += tolower(c);
    }
    
    return res;
}

struct Cmp
{
    bool operator()(FileData& fd1, FileData& fd2)
    {
        // 1. HEAD 기준 사전순 정렬. 대소문자 구분 X
        string head1 = ToLower(fd1.head);
        string head2 = ToLower(fd2.head);
        if(head1 != head2)
            return head1 > head2;

        // 2. NUMBER 순자 순으로 정렬. 012와 12는 같은 순위로 처리
        int number1 = stoi(fd1.number);
        int number2 = stoi(fd2.number);
        if(number1 != number2)
            return number1 > number2;

        // 3. 그 외의 경우 기존 정렬순으로 정렬.
        return fd1.idx > fd2.idx;
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    priority_queue<FileData, vector<FileData>, Cmp> pq;
    
    // Process
    for(int i = 0; i < files.size(); i++)
    {
        string& fileName = files[i];
        string head = "";
        string number = "";
        string tail = "";
        
        int pos = 0;
        
        // head
        while(isdigit(fileName[pos]) == false)
        {
            head += fileName[pos++];
        }
        
        // number
        int digits = 0;
        while(digits <= 5 && isdigit(fileName[pos]))
        {
            number += fileName[pos++];
            digits++;
        }
        
        // tail
        tail = fileName.substr(pos);
        
        // printf("%s %s %s\n", head.c_str(), number.c_str(), tail.c_str());
        
        pq.push({head, number, tail, i});
    }
    
    while(!pq.empty())
    {
        FileData fd = pq.top(); pq.pop();
        answer.push_back(fd.head + fd.number + fd.tail);
    }    
    
    return answer;
}
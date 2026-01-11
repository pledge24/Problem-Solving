#include <bits/stdc++.h>

using namespace std;

// 순서있는 열거(또는 순서를 따르는) 집합 -> 튜플
// 중복 가능
// 순서 있음
// 원소 개수는 유한
// 중복 X 튜플 => 집합 표현 가능({})
// 목표: "중복이 없는 튜플"을 표현하는 집합들이 주어졌을때 튜플을 찾아라.

// 체크
// 1개 -> 2개 -> 3개 -> 4개 이런식으로 표현. 시작은 항상 첫번째 원소
// s의 길이는 100만 -> 전부 순회해도 100만 이하라는 뜻

// 풀이 아이디어
// split 해서 각각 cnt를 올려준다. 
// cnt가 1인것부터 차례대로 push_back 한다.
// 어떤 자료구조에? 일단 unordered_map에 넣어놓고, move로 vector로 가져온다음, sort

void EraseBrace(string& s)
{
    int len = s.length();
    s.erase(len-1, 1);
    s.erase(0, 1);
}

void Split(string& s, vector<string>& outSplitted, const string& delimeter, int offset = 0)
{
    int pos = 0;
    while(pos < s.length())
    {
        int nextDelimeterPos = s.find(delimeter, pos);
        if(nextDelimeterPos == string::npos)
            nextDelimeterPos = s.length();
        
        int len = nextDelimeterPos - pos + offset;
        
        if(len > 0)
        {
            string str = s.substr(pos, len);
            // cout << str << '\n';
            outSplitted.push_back(std::move(str));
        }
        
        pos = nextDelimeterPos + delimeter.size();
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    
    EraseBrace(s);
    
    vector<string> outSplitted;
    Split(s, outSplitted, "},", 1);
    
    unordered_map<int, int> m;
    for(string& s : outSplitted)
    {
        EraseBrace(s);
        vector<string> numList;
        Split(s, numList, ",");
        
        for(string& x : numList)
        {
            int num = stoi(x);
            m[num]++;
        }
    }
    
    vector<pair<int, int>> v1;
    for(auto& p : m)
    {
        v1.push_back(make_pair(p.second, p.first));
    }
    
    sort(v1.begin(), v1.end(), greater<pair<int, int>>());
    
    for(auto& elem : v1)
    {
        answer.push_back(elem.second);
    }
    
    return answer;
}
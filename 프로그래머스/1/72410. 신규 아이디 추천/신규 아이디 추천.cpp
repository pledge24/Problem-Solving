#include <bits/stdc++.h>

using namespace std;

// 첫 업무: 신규 가입 유저의 아이디가 규칙에 맞지 않았을때 -> 유사한 아이디를 추천
// 1) 3 <= 아이디의 길이 <= 15
// 2) 소문자, 숫자, 특수문자(-, _, .)
// 2-1) 단, 마침표는 처음과 끝 사용 X, 연속으로도 사용 X

// 7단계를 거쳐 진행
// 7단계의 처리 과정을 거친 후의 추천 아이디는?
string solution(string new_id) {
    string answer = "";
    
    // 1단계: 대문자 -> 소문자
    {
        for(char& c : new_id){
            c = tolower(c);
        }
    }
    
    
    // 2단계: 유효한 문자가 아닌 문자 제거
    {
        string temp = "";
        vector<char> specialChar = {'-', '_', '.'};
        for(char& c : new_id){
            if(isalpha(c) || isdigit(c) || 
               find(specialChar.begin(), specialChar.end(), c) != specialChar.end()){
                temp += c;
            }
        }
        new_id = temp;
    }
    
    
    // 3단계: 마침표 연속 -> 마침표 1개
    {
        string temp = "";
        bool streaks = false;
        for(char& c : new_id){
            if(c != '.'){
                temp += c;
                streaks = false;
            }
            
            if(c == '.' && streaks == false){
                temp += c;
                streaks = true;
            }
        }
        new_id = temp;
    }
    
    // 4단계: 처음과 끝에 있는 .제거
    {
        if(new_id.front() == '.')
            new_id.erase(0, 1);
        
        if(new_id.back() == '.')
            new_id.pop_back();
    }
    
    // 5단계: 빈 문자열이면 "a"를 대입
    {
        if(new_id.length() == 0)
            new_id += 'a';
    }
    
    // 6단계: 길이가 16자 이상이면, 첫 15개 문자만 남긴다.
    {
        if(new_id.length() >= 16)
            new_id = new_id.substr(0, 15);
        
        if(new_id.back() == '.')
            new_id.pop_back();
    }
    
    // 7단계: 길이가 2자 이하라면, 길이가 3이 될때까지 마지막 문자를 반복
    {
        if(new_id.length() <= 2)
            while(new_id.length() < 3)
                new_id += new_id.back();
    }
    
    answer = new_id;
    
    return answer;
}
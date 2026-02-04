#include <bits/stdc++.h>

using namespace std;

// 유사한 기사를 묶는다.
// 자카드 유사도?
// -> J(A, B) => 두 집합의 교집합 크기 / 두 집합의 합집합 크기
// -> 원소의 중복을 허용하는 다중집합에 대해 확장 가능
// A 1 3개, B 1 5개 -> J(A, B) ==> 교집합은 3(min), 합집합은 5(max)
// 1) 문자열을 두 글자씩 끊어서 다중집합의 원소로 사용. -> 단 연속된 경우만 포함시킨다.
// 2) 영문자(대,소문자 포함)있고, 그 외 문자가 있다면 해당 글자 쌍을 버린다.
// 나눈값에 65536을 곱한 다음 소수점을 버려 출력해라
struct elemData
{
    int firstCnt = 0;
    int secondCnt = 0;
};

int solution(string str1, string str2) {
    int answer = 0;
    
    map<string, elemData> m1;
    for(int i = 0; i < str1.length()-1; i++)
    {
        if(isalpha(str1[i]) && isalpha(str1[i+1]))
        {
            string s = {(char)tolower(str1[i]), (char)tolower(str1[i+1])};
            m1[s].firstCnt++;
        }
    }
    
    for(int i = 0; i < str2.length()-1; i++)
    {
        if(isalpha(str2[i]) && isalpha(str2[i+1]))
        {
            string s = {(char)tolower(str2[i]), (char)tolower(str2[i+1])};
            m1[s].secondCnt++;
        }
    }
    
    int crossN = 0;
    int sumN = 0;
    for(auto& p : m1)
    {
        elemData ed = p.second;
        crossN += min(ed.firstCnt, ed.secondCnt);
        sumN += max(ed.firstCnt, ed.secondCnt);
    }
    
    // cout << crossN << " " << sumN << '\n';
    
    answer = (crossN + sumN) > 0 ? (crossN / (float)sumN) * 65536.f : 65536.f;
    
    return answer;
}
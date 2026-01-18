#include <bits/stdc++.h>

using namespace std;

// aabbaccc -> 2a2ba3c (압축률이 낮음)
// 2개 단위로 자르면 더 압축이 잘 됨?
// 1개 이상 단위로 문자열을 잘랐을때 가장 짧은 것의 길이
int GetShortestLen(string& s, int unit_size)
{
    struct ZipData
    {
        int lastZip = -1;   // 문자열 시작 부분
        int streakN = 0;
        vector<int> streakList;
    };
    
    map<string, ZipData> zipCnt;
   
    for(int i = unit_size; i < s.length()-unit_size+1; i += unit_size)
    {
        if(s.length() - i < unit_size)
            break;
        
        // unit_size 만큼 뒤에 있는 문자열과 같은지 체크
        const string& str1 = s.substr(i-unit_size, unit_size);
        const string& str2 = s.substr(i, unit_size);
        if(str1 == str2)
        {
            ZipData& zd = zipCnt[str2];
            if(zd.lastZip == i-unit_size)
            {
                zd.lastZip = i;
                zd.streakN++;
            }
            else
            {
                if(zd.streakN > 0)
                    zd.streakList.push_back(zd.streakN);
                zd.lastZip = i;
                zd.streakN = 2;
            }
        }
    }
    
    int totalZipCnt = 0;
    for(auto& p : zipCnt)
    {
        ZipData& zd = p.second;
        if(zd.streakN >= 2)
        {
            zd.streakList.push_back(zd.streakN);
            zd.streakN = 0;
        }
        
        // cout << p.first << " streakList: " << zd.streakList.size() << '\n';
        for(int streakN : zd.streakList)
        {
            // cout << (streakN - 1) * unit_size << " " << to_string(streakN).length() << '\n';
            totalZipCnt += (streakN - 1) * unit_size - to_string(streakN).length();
        }
    }
    
    int res = s.length() - totalZipCnt;
    
    return res;
}

int solution(string s) {
    int answer = s.length();
    int half = s.length() / 2;
    
    for(int unit_size = 1; unit_size <= half; unit_size++)
    {
        int sLen = GetShortestLen(s, unit_size);
        // cout << "unit_size: " << unit_size << " sLen: " << sLen << '\n';
        answer = min(answer, sLen);
    }
    
    return answer;
}
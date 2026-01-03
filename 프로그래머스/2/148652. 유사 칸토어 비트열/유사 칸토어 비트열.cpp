#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int64 MAXN = 20;
constexpr int64 sectionN = 5;
int64 sectionSizeList[MAXN+1];
int64 numOfOneList[MAXN+1];

void FillList()
{
    sectionSizeList[0] = 0;
    sectionSizeList[1] = 1;
    
    numOfOneList[0] = 1;
    numOfOneList[1] = 4;
    
    for(int i = 2; i <= MAXN; i++)
    {
        sectionSizeList[i] = 5*sectionSizeList[i-1];
        numOfOneList[i] = 4*numOfOneList[i-1];
    }
}

// n: n번째 칸토어
// offset 포함 왼쪽 1의 개수 반환
int64 GetLeftCount(int64 n, int64 offset)
{
    if(n == 1)
    {
        if(offset < 2)
            return offset+1;
        else 
            return offset;
    }
    
    // n이 2이상일 때만 진입.
    int64 sectionSize = sectionSizeList[n];
    int64 sectionIdx = offset / sectionSize;
    int64 cnt = 0;
    
    for(int64 i = 0; i < sectionIdx; i++)
    {
        if(i != 2)
            cnt += numOfOneList[n-1];
    }
    
    if(sectionIdx != 2)
    {
        offset -= sectionIdx*sectionSize;
        cnt += GetLeftCount(n-1, offset);
    }
    
    return cnt;
}

int64 GetBit(int64 n, int64 pos)
{
    while(n > 1)
    {
        int64 sectionSize = sectionSizeList[n];
        if(pos / sectionSize == 2)
            return 0;
        
        pos %= sectionSize;
        n--;
    }
    
    return pos != 2;
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    FillList();
    l--;
    r--;
    
    int64 lCnt = GetLeftCount(n, l);
    int64 rCnt = GetLeftCount(n, r);
    
    answer = rCnt - lCnt + GetBit(n, l);
    
    return answer;
}
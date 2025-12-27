#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int GetInDots(int64 x, int64 r, bool boundary = true)
{
    double maxY = sqrt(r*r - x*x);
    int64 inDots = floor(maxY)*2 + 1;
    
    if(!boundary)
    {
        if(maxY == floor(maxY))
        {
            inDots = max(inDots-2, (int64)0);
        }
    }
    
    return inDots;
}

long long solution(int r1, int r2) {
    long long answer = 0;
    
    int64 r1Dots = 0;
    for(int i = -r1; i <= r1; i++)
    {
        r1Dots += GetInDots(i, r1, false);
    }
    
    int64 r2Dots = 0;
    for(int i = -r2; i <= r2; i++)
    {
        r2Dots += GetInDots(i, r2);
    }
    
    // cout << r1Dots << " " << r2Dots << '\n';
    answer = r2Dots - r1Dots;
    return answer;
}
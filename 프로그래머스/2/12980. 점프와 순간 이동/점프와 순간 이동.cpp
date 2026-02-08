#include <bits/stdc++.h>

using namespace std;

// K칸 이동 -> K만큼 추가 사용
// 2배 점프 -> 추가 소모 X
int solution(int n)
{
    int ans = 0;
    while(n > 0)
    {
        ans += n % 2;
        n /= 2;
    }
    
    return ans;
}
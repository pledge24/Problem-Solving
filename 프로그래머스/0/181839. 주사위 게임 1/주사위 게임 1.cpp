#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int type = (a % 2) + (b % 2);

    if(type == 2)
    {
        answer = a*a + b*b;
    }
    else if(type == 1)
    {
        answer = 2*(a+b);
    }
    else
    {
        answer = abs(a - b);
    }
    
    return answer;
}
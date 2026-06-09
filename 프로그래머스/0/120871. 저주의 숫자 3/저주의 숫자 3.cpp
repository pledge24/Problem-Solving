#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int num = 1;
    int num3x = 1;
    while(num < n)
    {
        do  num3x++;
        while(num3x % 3 == 0 || (to_string(num3x).find('3') != string::npos));
            
        num++;
    }
    
    answer = num3x;
    
    return answer;
}
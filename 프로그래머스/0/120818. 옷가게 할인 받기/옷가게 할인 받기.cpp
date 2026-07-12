#include <bits/stdc++.h>

using namespace std;

int solution(int price) {
    int answer = 0;
    
    float discount = 0.f;
    if(price < 100'000)
        discount = 0.f;
    else if(price < 300'000)
        discount = 0.05f;
    else if(price < 500'000)
        discount = 0.1f;
    else
        discount = 0.2f;
    
    answer = (float)price * (1.f - discount);
    
    return answer;
}
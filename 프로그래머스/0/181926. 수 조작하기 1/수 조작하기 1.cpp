#include <bits/stdc++.h>

using namespace std;

map<char, function<void(int&)>> controlMappings = 
{
    make_pair('w', [](int& num){ num++; }),
    make_pair('s', [](int& num){ num--; }),
    make_pair('d', [](int& num){ num += 10; }),
    make_pair('a', [](int& num){ num -= 10; })
};

int solution(int n, string control) {
    int answer = 0;
    
    for(char c : control)
    {
        controlMappings[c](n);
    }
    
    answer = n;
    
    return answer;
}
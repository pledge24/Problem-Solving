#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    for(int elem : array)
    {
        while(elem > 0)
        {
            answer += (elem % 10) == 7;
            elem /= 10;
        }
    }
        
    return answer;
}
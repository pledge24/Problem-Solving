#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = array[0];
    
    for(int elem : array)
    {
        if(abs(elem - n) < abs(answer - n))
            answer = elem;
        else if(abs(elem - n) == abs(answer - n))
            answer = min(elem, answer);
    }
    
    return answer;
}
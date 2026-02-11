#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    vector<int> next(arr.size());
    while(arr != next)
    {
        for(int i = 0; i < arr.size(); i++)
        {
            int elem = arr[i];
            if(elem >= 50 && elem % 2 == 0)
            {
                next[i] = elem / 2;
            }
            else if(elem < 50 && elem % 2)
            {
                next[i] = elem*2 + 1;
            }
            else
            {
                next[i] = elem;
            }
        }   
        
        answer++;
        arr.swap(next);
    }
    
    return answer - 1;
}
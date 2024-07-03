#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    int max_match = log2(n);
    
    int low = 1;
    int high = n;
    int mid = (low + high) / 2;
    int cnt = 0;
    
    while((a <= mid) == (b <= mid)){
       
        if(a <= mid){
            high = mid;
            mid = (low + high) / 2;
        }
        else{
            low = mid;
            mid = (low + high) / 2;
        }
        cnt++;
    }

    cout << max_match - cnt << '\n';
    answer = max_match - cnt;
    return answer;
}
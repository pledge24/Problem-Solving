#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int a = n;
    int b = 6;
    while(a > 0 && b > 0)
    {
        if(a < b)
            swap(a, b);
        
        a %= b;
    }
    
    int gdc = max(a, b);
    
    answer = n/gdc * 6/gdc * gdc / 6;
    return answer;
}
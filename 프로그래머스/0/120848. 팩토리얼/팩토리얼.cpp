#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int num = 1;
    while(num <= n)
    {
        answer++;
        num *= answer;
    }
    
    return answer - 1;
}
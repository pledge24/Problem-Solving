#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 2;
    
    for(int i = 0; i <= 1000; i++)
    {
        if(i*i == n)
            return 1;
    }
    return answer;
}
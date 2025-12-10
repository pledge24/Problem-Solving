#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    
    int nextNum = a;
    for(bool bIncluded : included)
    {
        answer += bIncluded ? nextNum : 0;
        nextNum += d;
    }
    return answer;
}
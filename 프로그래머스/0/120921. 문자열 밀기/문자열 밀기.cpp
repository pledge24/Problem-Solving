#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = -1;
    string temp = A+A;
    
    int aLen = A.length();
    for(int i = 0; i < aLen; i++)
    {
        if(temp.substr(aLen - i, aLen) == B)
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}
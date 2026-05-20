#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    
    int idx = code-1;
    while(idx < cipher.length())
    {
        answer += cipher[idx];
        idx += code;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

enum class Mode 
{
    ZERO_MODE = 0,
    ONE_MODE
};

string solution(string code) {
    string answer = "";
    Mode mode = Mode::ZERO_MODE;
    for(int i = 0; i < code.length(); i++)
    {
        char c = code[i];
        if(c == '1')
        {
            mode = mode == Mode::ZERO_MODE ? Mode::ONE_MODE : Mode::ZERO_MODE;
            continue;
        }
        
        if(mode == Mode::ZERO_MODE && (i % 2 == 0))
        {
            answer += c;
        }
        else if(mode == Mode::ONE_MODE && (i % 2 > 0))
        {
            answer += c;
        }
    }
    
    if(answer.length() == 0)
        return string("EMPTY");
    
    return answer;
}
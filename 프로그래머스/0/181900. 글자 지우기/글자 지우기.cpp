#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    
    vector<bool> validList(my_string.length(), true);
    for(int idx : indices)
    {
        validList[idx] = false;
    }
    
    for(int i = 0; i < my_string.length(); i++)
    {
        if(validList[i])
            answer += my_string[i];
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    for(int i = 0; i < my_strings.size(); i++)
    {
        vector<int>& part = parts[i];
        string& my_string = my_strings[i];
        int start = part[0];
        int end = part[1];
        
        answer += my_string.substr(start, (end-start+1));
    }
    return answer;
}
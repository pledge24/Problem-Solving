#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    int len = overwrite_string.length();
    my_string.replace(s, len, overwrite_string);
    string answer = my_string;
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    
    for(const string& o : order)
    {
        answer += o.find("cafelatte") != string::npos ? 5000 : 4500;
    }
    
    return answer;
}
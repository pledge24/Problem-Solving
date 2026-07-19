#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int x = 1;
    while(x <= n)
    {
        answer.push_back(x);
        x+=2;
    }
    
    return answer;
}
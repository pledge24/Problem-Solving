#include <string>
#include <vector>

using namespace std;


int solution(string ineq, string eq, int n, int m) {
    int answer = 0;
       
    string x = ineq + eq;
    if(x == ">=")
        answer = n >= m;
    else if(x == "<=")
        answer = n <= m;
    else if(x == ">!")
        answer = n > m;
    else if(x == "<!")
        answer = n < m;
    
    return answer;
}
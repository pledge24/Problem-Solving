#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int answer = 0;
    
    for(int elem : numbers)
    {
        answer += elem;
        if(answer > n)
            break;
    }
    return answer;
}
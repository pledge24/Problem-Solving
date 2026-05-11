#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = to_string(num).find(to_string(k));
    if(answer >= 0)
        answer++;
    
    return answer;
}
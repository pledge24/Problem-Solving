#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = -1;
    
    int n = 0;
    while(chicken >= 10)
    {
        int tickets = chicken / 10;
        n += tickets;
        chicken = (chicken % 10) + tickets;
    }
    
    answer = n;
    
    return answer;
}
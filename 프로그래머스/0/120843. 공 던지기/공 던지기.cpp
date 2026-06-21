#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    int N = numbers.size();
    int order = (k* 2 - 2) % N;
    
    answer = numbers[order];
    return answer;
}
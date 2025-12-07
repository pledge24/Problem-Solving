#include <string>
#include <vector>

using namespace std;

int solution(int number, int n, int m) {
    int answer = !(number % n) && !(number % m);
    return answer;
}
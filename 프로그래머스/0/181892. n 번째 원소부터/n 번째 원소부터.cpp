#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    std::copy(num_list.begin()+n-1, num_list.end(), back_inserter(answer));
    return answer;
}
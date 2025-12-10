#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer = num_list;
    
    int size = num_list.size();
    int lastNum = num_list.back();
    int addedNum = num_list[size-2] < lastNum ? lastNum - num_list[size-2] : lastNum*2;
    answer.push_back(addedNum);
    
    return answer;
}
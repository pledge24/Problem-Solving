#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    
    bool isSameGap = true;
    int gap = common[1] - common[0];
    for(int i = 1; i < common.size(); i++)
    {
        if(common[i] - common[i-1] != gap)
            isSameGap = false;
    }
    
    answer = isSameGap ? common.back() + gap : common.back() * common[1] / common[0];
    return answer;
}
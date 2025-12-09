#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    string oddStr = "";
    string evenStr = "";
    for(int num : num_list)
    {
        if(num % 2 > 0)
            oddStr += (num + '0');
        else
            evenStr += (num + '0');
    }
    
    answer = stoi(oddStr) + stoi(evenStr);
    
    return answer;
}
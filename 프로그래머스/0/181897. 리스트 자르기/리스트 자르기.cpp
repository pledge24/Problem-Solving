#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    
    int a = slicer[0];
    int b = slicer[1];
    int c = slicer[2];
    
    switch(n)
    {
        case 1:
        {
            std::copy(num_list.begin(), num_list.begin()+b+1, std::back_inserter(answer));
            break;
        }
        case 2:
        {
            std::copy(num_list.begin()+a, num_list.end(), std::back_inserter(answer));
            break;
        }
        case 3:
        {
            std::copy(num_list.begin()+a, num_list.begin()+b+1, std::back_inserter(answer));
            break;
        }
        case 4:
        {
            int idx = a;
            while(idx <= b)
            {
                answer.push_back(num_list[idx]);
                idx += c;
            }
            break;
        }    
        
    }
    return answer;
}
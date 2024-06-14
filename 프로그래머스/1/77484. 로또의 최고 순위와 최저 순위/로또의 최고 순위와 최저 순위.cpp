#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<bool> visited(6);
    
    int cnt = 0;
    int zero_n = 0;
    for(int elem : lottos){
        if(elem == 0){
            zero_n++;
            continue;
        }
        
        if(find(win_nums.begin(), win_nums.end(), elem) != win_nums.end()) cnt++;
    }
    
    int min_rank = cnt >= 2 ? 7 - cnt : 6;
    int max_rank = (cnt + zero_n) >= 2 ? 7 - (cnt + zero_n) : 6;
    answer = {max_rank, min_rank};
    return answer;
}
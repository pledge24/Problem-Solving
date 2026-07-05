#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    int odd = count_if(num_list.begin(), num_list.end(), [](int elem){
        return elem % 2 == 0;
    });
    
    answer = {odd, (int)num_list.size() - odd};
    
    return answer;
}
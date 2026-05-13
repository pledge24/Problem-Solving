#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    
    int idx = max_element(array.begin(), array.end()) - array.begin();
    answer = {array[idx], idx};
    
    return answer;
}
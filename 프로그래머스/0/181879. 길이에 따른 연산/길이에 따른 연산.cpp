#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> num_list) {
    int answer = num_list[0];
    for(int i = 1; i < num_list.size(); i++)
    {
        if(num_list.size() >= 11)
        {
            answer += num_list[i];
        }
        else
        {
            answer *= num_list[i];
        }
    }
    return answer;
}
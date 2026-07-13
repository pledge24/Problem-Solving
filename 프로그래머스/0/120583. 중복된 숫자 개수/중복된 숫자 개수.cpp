#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = std::count_if(array.begin(), array.end(), [n](int elem){
        return elem == n;
    });
    
    return answer;
}